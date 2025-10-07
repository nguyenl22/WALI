#!/bin/bash
ORIGINAL_DIR="$(pwd)"

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Change to the script directory
cd "$SCRIPT_DIR"
# If user specifies a file
if [ -n "$1" ]; then
  cfile="$(basename "$1")"
  if [ ! -f "$cfile" ]; then
    echo "Error: File '$cfile' not found in $SCRIPT_DIR"
    cd "$ORIGINAL_DIR"
    exit 1
  fi

  base_name="${cfile%.c}"
  $WALI_CC --target=wasm32-wasi-threads -O3 -pthread --sysroot=$WALI_SYSROOT_DIR \
    -L$WALI_SYSROOT_DIR/lib -matomics -mbulk-memory -mmutable-globals -msign-ext -Wl,--shared-memory \
    -Wl,--export-memory -Wl,--max-memory=67108864 \
    "$cfile" -o "${base_name}.wasm"
  if [ $? -eq 0 ]; then
    echo "Generated ${base_name}.wasm from ${cfile}"
  else
    echo "Failed to generate ${base_name}.wasm from ${cfile}"
  fi
else 
  # Loop through all .c files in the current directory
  for cfile in *.c; do
    # Skip if no .c files are found
    [ -e "$cfile" ] || continue

    # Get the base filename without extension
    base_name="${cfile%.c}"

    # Execute the iwasm command
    $WALI_CC --target=wasm32-wasi-threads -O3 -pthread --sysroot=$WALI_SYSROOT_DIR \
    -L$WALI_SYSROOT_DIR/lib -matomics -mbulk-memory -mmutable-globals -msign-ext -Wl,--shared-memory \
    -Wl,--export-memory -Wl,--max-memory=67108864 \
    "$cfile" -o "${base_name}.wasm"

    # Optional success message
    if [ $? -eq 0 ]; then
      echo "Generated ${base_name}.wasm from ${cfile}"
    else
      echo "Failed to generate ${base_name}.wasm from ${cfile}"
    fi
  done
fi

cd "$ORIGINAL_DIR"