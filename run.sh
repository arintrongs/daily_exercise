#!/bin/bash
g++ $1 -o out -std=c++17 -O2 && ./out < ./in