# DNA Sequence Analysis Toolkit

A C toolkit for evaluating DNA strings with common sequence-analysis operations.

## Features

- Calculates GC-content percentage
- Searches for motifs within a sequence
- Calculates genetic difference using Hamming distance
- Detects palindromic sequences
- Compares nucleotide composition between sequences

## Compile

```bash
gcc -Wall -Wextra -std=c99 -c dna_analysis.c
```

The public header exposes each analysis function for use in another C program.
