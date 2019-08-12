#!/bin/bash
ifconfig -a ether | grep -oE '([[:xdigit:]]{2}:){5}[[:xdigit:]]{2}'
