#!/usr/bin/env bash
#SBATCH --job-name=run_Cplusplus
#SBATCH --partition=instruction
#SBATCH --ntasks=1 --cpus-per-task=20 
#SBATCH --time=0-00:00:01
#SBATCH --output=run_Cplusplus.out
#SBATCH --error=run_Cplusplus.err
# log in the submission directory
cd $SLURM_SUBMIT_DIR
# load the gcc for compiling C++ programs
module load gcc/13.2.0
# clone (replace the github link to yours)
#git clone https://github.com/tsung-wei-huang/repo759.git
#cd repo759/HW01
g++ task2.cpp convolution.cpp -Wall -O3 -std=c++17 -o task2 -fopenmp


# Loop from 1-20
for (( i=1; i<=20; i++ )); do
    n=$((i))  # Calculate 2^i

    # Run your C++ program with n and capture the output
    # Assuming your C++ program is compiled as `task1` and outputs three numbers on separate lines
    result=$(./task2 1024 $n)

    # Extract the first number from the output (assuming it's the first line of the output)
    time_taken=$(echo "$result" | head -n 1)

    # Write n and time_taken to the output file
    echo "$i,$time_taken"
done

