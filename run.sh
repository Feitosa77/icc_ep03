#!/bin/bash

make

echo "Digite o valor do parâmetro: "
read Xe

likwid-perfctr -C 3 -g FLOPS_DP -m ./interpola $Xe < pontos.in > resultado.out

grep "DP MFLOP/s" < resultado.out

make purge

