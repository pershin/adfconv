#! /bin/sh

for filename in src/*; do
  clang-format --style=LLVM ${filename} > ${filename}.clang-format

  if cmp -s "${filename}" "${filename}.clang-format"; then
    rm ${filename}.clang-format
  else
    printf "%s formatted\n" $filename
    rm ${filename}
    mv ${filename}.clang-format ${filename}
  fi
done
