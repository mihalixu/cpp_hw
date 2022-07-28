#!/usr/bin/env python3

import argparse
import collections
import difflib
import os
import subprocess
import sys

from math import hypot, pi

CPP = 'g++ -std=c++17 -Wall -Wextra -Wconversion'.split()
FAIL = '\033[91m'
ENDC = '\033[0m'
MAX_TOTAL = 9.0

Test = collections.namedtuple('Test', ['file', 'input', 'expected'])

tests = [
    Test("simplemath.cpp", "",
         "31\n"),
    Test("circle.cpp", "3\n",
         "Enter a radius: "
         "The circle has an area of 28.27\n"
         "The perimeter of this circle is 18.85\n"),
    Test("imperial_units.cpp", "1.3\n",
         "Enter a distance in meters: "
         "51.18 inch\n"
         "4.27 feet\n"
         "1.42 yards\n"
         "0.00 miles\n"),
    Test("trigonometry.cpp", "",
         """radians |  sine | cosine
------------------------
    0.0 |  0.00 |   1.00
    0.1 |  0.10 |   1.00
    0.2 |  0.20 |   0.98
    0.3 |  0.30 |   0.96
    0.4 |  0.39 |   0.92
    0.5 |  0.48 |   0.88
    0.6 |  0.56 |   0.83
    0.7 |  0.64 |   0.76
    0.8 |  0.72 |   0.70
    0.9 |  0.78 |   0.62
    1.0 |  0.84 |   0.54
    1.1 |  0.89 |   0.45
    1.2 |  0.93 |   0.36
    1.3 |  0.96 |   0.27
    1.4 |  0.99 |   0.17
    1.5 |  1.00 |   0.07
    1.6 |  1.00 |  -0.03
    1.7 |  0.99 |  -0.13
    1.8 |  0.97 |  -0.23
    1.9 |  0.95 |  -0.32
    2.0 |  0.91 |  -0.42
    2.1 |  0.86 |  -0.50
    2.2 |  0.81 |  -0.59
    2.3 |  0.75 |  -0.67
    2.4 |  0.68 |  -0.74
    2.5 |  0.60 |  -0.80
    2.6 |  0.52 |  -0.86
    2.7 |  0.43 |  -0.90
    2.8 |  0.33 |  -0.94
    2.9 |  0.24 |  -0.97
    3.0 |  0.14 |  -0.99
    3.1 |  0.04 |  -1.00
   3.14 |  0.00 |  -1.00
"""),
    Test("distance.cpp", "3.0\n7.0\n-2.0\n3.0\n",
         "First point's x-coordinate: "
         "First point's y-coordinate: "
         "Second point's x-coordinate: "
         "Second point's y-coordinate: "
         "The euclidean distance between the two points is 6.4031.\n"),
    Test("equations.cpp", ['2', '2', '-7.5'],
         "x1: 1.5; x2: -2.5\n"),
    Test("addition.cpp", ['10'],
         "sum: 55\n"),
    Test("geometry.cpp", ['2.2', '3.1'],
         "surface_cylinder({r:.2f}, {h:.2f}): {0:.2f}\n"
         "volume_cylinder({r:.2f}, {h:.2f}): {1:.2f}\n"
         "surface_cone({r:.2f}, {h:.2f}): {2:.2f}\n"
         "volume_cone({r:.2f}, {h:.2f}): {3:.2f}\n"
         .format(2 * 2.2 * 2.2 *pi + 2 * 2.2 * pi * 3.1,
                 2.2 * 2.2 * pi * 3.1,
                 2.2 * 2.2 * pi + 2.2 * pi * hypot(2.2, 3.1),
                 2.2 * 2.2 * pi * 3.1 / 3.0,
                 r=2.2, h=3.1)),
    Test("business.cpp", ['100', '0.1', '2', '0.2'],
         "interest: 16.64\n"
         "terminal value: 116.64\n")
    ]


def get_binary_name(test):
    """Return the name of the binary for this test."""
    filepath = os.path.dirname(__file__)
    if not filepath:
        filepath = './'
    return os.path.join(filepath, os.path.splitext(test.file)[0])


def delete_binary(test):
    """Remove the binary for this test."""
    try:
        os.remove(get_binary_name(test))
    except FileNotFoundError:
        pass


def compile_(test):
    """Compile the test and return true if there are no warnings."""
    process = subprocess.Popen(CPP + ["-o",
                               get_binary_name(test), test.file],
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)
    out, err = process.communicate()
    errors_and_warnings = out.decode("utf-8") + err.decode("utf-8")
    if errors_and_warnings:
        print("{} had warnings or errors during compilation".format(test.file),
              file=sys.stderr)
        print('"""')
        print(FAIL + errors_and_warnings + ENDC, file=sys.stderr, end='')
        print('"""')
        return False
    return True


def grade(test):
    """Grade a submitted example."""
    if not compile_(test):
        print("no points for " + test.file)
        return 0
    command = [get_binary_name(test), ]
    if isinstance(test.input, list):
        command += test.input
    process = subprocess.Popen(command,
                               stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)
    if isinstance(test.input, str):
        out, err = process.communicate(test.input.encode("utf-8"))
    else:
        out, err = process.communicate()
    actual = out.decode("utf-8")
    if test.expected == actual:
        return 1
    else:
        print("{} is not correct".format(test.file))
        if err:
            print("error:\n", err.decode('utf-8'))
        else:
            for line in difflib.context_diff(actual.splitlines(True),
                                             test.expected.splitlines(True),
                                             fromfile='actual',
                                             tofile='expected'):
                sys.stdout.write(line)
            #print("actual:\n", actual)
            #print("expected:\n", test.expected)
    return 0


def main():
    global tests
    parser = argparse.ArgumentParser()
    parser.add_argument("--test", help="C++ files to grade.", nargs='+',
                        default='all')
    parser.add_argument("--clean", action='store_true',
        help="Remove generated executables and exit.")
    args = parser.parse_args()
    if args.test != 'all':
        tests = [t for t in tests if t.file in args.test]
    if not len(tests):
        print("no tests given (maybe you forgot '.cpp' at the end of the test?")
        return 1
    if args.clean:
        for t in tests:
            delete_binary(t)
        return 0
    total = 0
    for test in tests:
        total += grade(test)
    if args.test == 'all':
        print()
        print("{}/{} in total".format(total / len(tests) * MAX_TOTAL,
                                      MAX_TOTAL))
    else:
        print()
        print("{}% passed".format(round(total / len(tests) * 100)))
    return 0

if __name__ == "__main__":
    sys.exit(main())
