#!/bin/bash

# -------------------------------
# Duplicate Submission Detector
# -------------------------------

# Create backup directory if it does not exist
mkdir -p backup

# Initialize counters
processed=0
duplicates=0
backedup=0

# Clear previous report and error log
> duplicate_report.txt
> error.log

# Associative array to store hashes
declare -A file_hashes

# Process every file in submissions folder
for file in submissions/*
do
    if [ -f "$file" ]; then

        ((processed++))

        # Generate SHA-256 hash
        hash=$(sha256sum "$file" 2>>error.log | awk '{print $1}')

        # Check whether hash already exists
        if [[ -n "${file_hashes[$hash]}" ]]; then

            ((duplicates++))

            echo "$(basename "$file") is a duplicate of ${file_hashes[$hash]}" >> duplicate_report.txt

        else

            file_hashes[$hash]=$(basename "$file")

            cp "$file" backup/ 2>>error.log

            ((backedup++))

        fi

    fi
done

echo "" >> duplicate_report.txt
echo "========== REPORT ==========" >> duplicate_report.txt
echo "Files Processed : $processed" >> duplicate_report.txt
echo "Duplicate Files : $duplicates" >> duplicate_report.txt
echo "Files Backed Up : $backedup" >> duplicate_report.txt

echo "Task Completed Successfully."
