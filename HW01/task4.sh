#!/usr/bin/env bash

#SBATCH --job-name=FirstSlurm
#SBATCH --partition=instruction
#SBATCH --ntasks=1 --cpus-per-task=2
#SBATCH --time=0-00:00:10
#SBATCH --output=FirstSlurm.out
#SBATCH --error=FirstSlurm.err


hostname

