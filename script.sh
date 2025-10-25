#!/usr/bin/env bash

# Base directory containing subdirectories
SRC_DIR="src"

# Loop over each subdirectory
for dir in "$SRC_DIR"/*/; do
  # Remove trailing slash
  dir="${dir%/}"

  # Extract base name of the subdirectory
  base=$(basename "$dir")

  # Original .cpp file
  cpp_file="$dir/$base.cpp"
  no_comments_file="$dir/${base}_no_comments.cpp"

  # Check if the .cpp file exists
  if [[ -f "$cpp_file" ]]; then
    echo "Processing $cpp_file..."

    # Remove single-line and multi-line comments
    # - Remove // comments
    # - Remove /* */ comments (multi-line)
    # Using sed for simplicity
    sed -E 's://.*$::; s:/\*.*\*/::g' "$cpp_file" > "$no_comments_file"

    echo "Created $no_comments_file"
  else
      echo "Warning: $cpp_file does not exist."
  fi

  # Ensure test file exists
  if [[ ! -f "$dir/test.cpp" ]]; then
    touch "$dir/test.cpp"
    echo "Created empty $dir/test.cpp"
  fi
done

echo "Done :)"
