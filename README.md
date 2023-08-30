# SeqTk
# Language: C++
# Input: TXT
# Output: FASTQ
# Tested with: PluMA 1.0, GCC 4.8.4
# Dependency: SeqTk 1.4

Randomly subsample reads from a FASTQ.

Input is a tab-delimited text file of keyword-value pairs:
seed: Random number seed
fastq: Input FASTQ file of reads
frac: Percentage of the sample (0 to 1)

Subsample will be output to the user-specified FASTQ.
