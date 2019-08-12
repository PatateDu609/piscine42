#!/bin/bash

find . -type f -name "*.sh" -exec basename {} \; | sed -e "s/$1\.sh/$1/g"
