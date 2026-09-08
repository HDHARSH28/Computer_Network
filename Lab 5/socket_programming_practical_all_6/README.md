# Socket Programming Lab - Easy Start Guide

## Quick Commands

### Build Everything (One Command!)
```bash
make
```

### Run Any Program
```bash
./Q1_Stop_Wait/sender
./Q1_Stop_Wait/receiver
./Q2_Stop_Wait_ARQ/sender_arq
# etc...
```

### Clean All Builds
```bash
make clean
```

### Interactive Menu (Recommended)
```bash
chmod +x run.sh
./run.sh
```

### View All Options
```bash
make help
```

---

## Project Structure

```
├── Makefile              ← Builds everything with: make
├── run.sh               ← Interactive menu to run programs
├── README.md            ← This file
│
├── Q1_Stop_Wait/
│   ├── sender.c
│   ├── receiver.c
│   ├── sender           ← Built executable
│   └── receiver         ← Built executable
│
├── Q2_Stop_Wait_ARQ/    ← Stop & Wait with ACKs
├── Q3_Sliding_Window/   ← Sliding Window Protocol
├── Q4_Go_Back_N/        ← Go Back N ARQ
├── Q5_Selective_Repeat/ ← Selective Repeat ARQ
└── Q6_Error_Control/    ← CRC & Hamming Code
```

---

## What Each Question Does

| Question | Protocol | Files | Purpose |
|----------|----------|-------|---------|
| Q1 | Stop & Wait | sender, receiver | Basic reliable transmission |
| Q2 | Stop & Wait ARQ | sender_arq, receiver_arq | With acknowledgments |
| Q3 | Sliding Window | sliding_sender, sliding_receiver | Pipeline protocol |
| Q4 | Go Back N | gbn_sender, gbn_receiver | Selective retransmit (N) |
| Q5 | Selective Repeat | sr_sender, sr_receiver | Selective retransmit (1) |
| Q6 | Error Control | crc, hamming | CRC and Hamming codes |

---

## Usage Examples

### Example 1: Run Everything with One Command
```bash
make && make help
```

### Example 2: Build, then run Q1 sender
```bash
make
./Q1_Stop_Wait/sender
```

### Example 3: Test Q2 (two terminals)
```bash
# Terminal 1
make
./Q2_Stop_Wait_ARQ/sender_arq

# Terminal 2
./Q2_Stop_Wait_ARQ/receiver_arq
```

### Example 4: Clean and rebuild
```bash
make clean
make
```

---

## Troubleshooting

**"make: command not found"**
- Install make: `brew install make` (macOS)

**"Permission denied" on run.sh**
- Run: `chmod +x run.sh`

**Compilation errors**
- Check gcc is installed: `gcc --version`
- Install if needed: `brew install gcc`

---

## Made with ❤️ - Now Everything is Easy!
