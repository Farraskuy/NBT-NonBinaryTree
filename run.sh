#!/bin/bash

OUTPUT="program"

gcc *.c -o $OUTPUT

if [ $? -eq 0 ]; then
    echo "Kompilasi berhasil. Menjalankan program..."
    ./$OUTPUT
else
    echo "Kompilasi gagal."
fi
