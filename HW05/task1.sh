#!/usr/bin/env bash
#SBATCH --job-name=run_CUDA
#SBATCH --partition=instruction
#SBATCH --ntasks=1 --cpus-per-task=1
#SBATCH --time=0-00:00:01
#SBATCH --output=run_CUDA_guided.out
#SBATCH --error=run_CUDA_guided.err
#SBATCH --gres=gpu:1  # Request one GPU

# Log in to the submission directory
cd $SLURM_SUBMIT_DIR

module load nvidia/cuda/11.8.0
module load gcc/11.3.0

# Compile the CUDA code (replace 'task3_guided.cu' with your .cu file)
nvcc task1.cu -Xcompiler -O3 -Xcompiler -Wall -Xptxas -O3 -std=c++17 -o task1

# Run the compiled CUDA program
./task1
