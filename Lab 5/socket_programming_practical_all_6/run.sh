#!/bin/bash

# Socket Programming Lab - Quick Run Script
# Makes it easy to run and test any program

set -e

show_menu() {
    echo ""
    echo "╔════════════════════════════════════════╗"
    echo "║  Socket Programming Lab - Quick Run   ║"
    echo "╚════════════════════════════════════════╝"
    echo ""
    echo "Q1) Stop & Wait Protocol"
    echo "Q2) Stop & Wait ARQ"
    echo "Q3) Sliding Window"
    echo "Q4) Go Back N"
    echo "Q5) Selective Repeat"
    echo "Q6) Error Control (CRC/Hamming)"
    echo "B)  Build All"
    echo "C)  Clean All"
    echo "H)  Help"
    echo "Q)  Quit"
    echo ""
}

run_program() {
    local dir=$1
    local prog_type=$2
    
    echo ""
    echo "Built executables in $dir:"
    ls -la "$dir" | grep -E '(sender|receiver|crc|hamming)' | grep -v '.c' | awk '{print $NF}'
    echo ""
    echo "Choose which program to run:"
    ls -lh "$dir" | grep -E '(sender|receiver|crc|hamming)' | grep -v '.c' | awk '{print $NF}' | nl
    echo ""
    read -p "Enter program number (or press Enter to skip): " choice
    
    if [ -z "$choice" ]; then
        return
    fi
    
    prog=$(ls "$dir" | grep -E '(sender|receiver|crc|hamming)' | grep -v '.c' | sed -n "${choice}p")
    
    if [ -z "$prog" ]; then
        echo "Invalid choice"
        return
    fi
    
    echo ""
    echo "Running: $dir/$prog"
    echo "Press Ctrl+C to stop"
    echo ""
    "./$dir/$prog"
}

# Main loop
while true; do
    show_menu
    read -p "Enter choice: " choice
    
    case $choice in
        Q1|q1) make all > /dev/null 2>&1 && run_program "Q1_Stop_Wait" "Stop & Wait" ;;
        Q2|q2) make all > /dev/null 2>&1 && run_program "Q2_Stop_Wait_ARQ" "Stop & Wait ARQ" ;;
        Q3|q3) make all > /dev/null 2>&1 && run_program "Q3_Sliding_Window" "Sliding Window" ;;
        Q4|q4) make all > /dev/null 2>&1 && run_program "Q4_Go_Back_N" "Go Back N" ;;
        Q5|q5) make all > /dev/null 2>&1 && run_program "Q5_Selective_Repeat" "Selective Repeat" ;;
        Q6|q6) make all > /dev/null 2>&1 && run_program "Q6_Error_Control" "Error Control" ;;
        B|b)
            echo "Building all projects..."
            make all
            echo "✓ Build complete!"
            ;;
        C|c)
            echo "Cleaning all projects..."
            make clean
            echo "✓ Clean complete!"
            ;;
        H|h)
            cat << 'EOF'

QUICK START GUIDE
=================

1. Build all projects:
   make

2. Clean all projects:
   make clean

3. Run individual programs:
   ./Q1_Stop_Wait/sender
   ./Q1_Stop_Wait/receiver
   ./Q2_Stop_Wait_ARQ/sender_arq
   etc...

4. Interactive menu (this script):
   ./run.sh

5. See all options:
   make help

EOF
            ;;
        Q|q) exit 0 ;;
        *) echo "Invalid choice. Try again." ;;
    esac
done
