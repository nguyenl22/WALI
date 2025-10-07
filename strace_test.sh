#!/bin/bash

# Check if the correct number of arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <input_directory> <output_directory>"
    exit 1
fi

# Assign input directory and output directory variables
input_directory="$1"
output_directory="$2"

# Check if the input directory exists
if [ ! -d "$input_directory" ]; then
    echo "Input directory '$input_directory' does not exist."
    exit 1
fi

# Check if the output directory exists, if not, create it
if [ ! -d "$output_directory" ]; then
    mkdir -p "$output_directory"
fi

# Set log file
log_file="$output_directory/log.txt"

# Iterate over all files with .wasm extension in the input directory
for wasm_file in "$input_directory"/*.wasm; do
    if [ -f "$wasm_file" ]; then
        # Ensure it's a .wasm file and not a .int.wasm file
        if [[ "$wasm_file" != *".int.wasm" && "$wasm_file" != *"infinite_loop"* && "$wasm_file" != *"sig"* && "$wasm_file" != *"socket_server"* && "$wasm_file" != *"streamin"*  ]]; then
            # Extract the base file name without extension
            base_name=$(basename -s .wasm "$wasm_file")
            # Construct the output file path
            output_file="$output_directory/$base_name.strace"
            # Execute the command on the wasm file and save the output to the generated file
            {
                ./iwasm -v=0 --stack-size=524288 --strace="$output_file" "$wasm_file"
            } 2>&1 | tee -a "$log_file"
        fi
    fi
done
