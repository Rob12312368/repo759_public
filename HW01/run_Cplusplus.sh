#!/usr/bin/env bash
#SBATCH --job-name=run_Cplusplus
#SBATCH --partition=instruction
#SBATCH --ntasks=1 --cpus-per-task=2
#SBATCH --time=0-00:00:10
#SBATCH --output=run_Cplusplus.out
#SBATCH --error=run_Cplusplus.err
# log in the submission directory
cd $SLURM_SUBMIT_DIR
# load the gcc for compiling C++ programs
module load gcc/13.2.0
# clone (replace the github link to yours)
#git clone https://github.com/tsung-wei-huang/repo759.git
#cd repo759/HW01
g++ task6.cpp -Wall -O3 -std=c++17 -o task6
./task6 10
