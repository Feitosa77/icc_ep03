#!/bin/bash

make

read Xe

echo "performance" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governo

likwid-perfctr -C 3 -g FLOPS_DP -m ./interpola $Xe < pontos.in > resultado.out # grep "DP MFLOP/s"

echo "powersave" > /sys/devices/system/cpu/cpufreq/policy3/scaling_governor

