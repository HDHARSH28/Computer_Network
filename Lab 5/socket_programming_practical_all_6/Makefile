# Socket Programming Lab - Master Makefile
# Compiles all projects in one command

CC = gcc
CFLAGS = -Wall -Wextra -g -O0

# Define all executable targets
TARGETS = \
	Q1_Stop_Wait/sender \
	Q1_Stop_Wait/receiver \
	Q2_Stop_Wait_ARQ/sender_arq \
	Q2_Stop_Wait_ARQ/receiver_arq \
	Q3_Sliding_Window/sliding_sender \
	Q3_Sliding_Window/sliding_receiver \
	Q4_Go_Back_N/gbn_sender \
	Q4_Go_Back_N/gbn_receiver \
	Q5_Selective_Repeat/sr_sender \
	Q5_Selective_Repeat/sr_receiver \
	Q6_Error_Control/crc \
	Q6_Error_Control/hamming

.PHONY: all clean help

all: $(TARGETS)

# Q1: Stop & Wait
Q1_Stop_Wait/sender: Q1_Stop_Wait/sender.c
	$(CC) $(CFLAGS) $< -o $@

Q1_Stop_Wait/receiver: Q1_Stop_Wait/receiver.c
	$(CC) $(CFLAGS) $< -o $@

# Q2: Stop & Wait ARQ
Q2_Stop_Wait_ARQ/sender_arq: Q2_Stop_Wait_ARQ/sender_arq.c
	$(CC) $(CFLAGS) $< -o $@

Q2_Stop_Wait_ARQ/receiver_arq: Q2_Stop_Wait_ARQ/receiver_arq.c
	$(CC) $(CFLAGS) $< -o $@

# Q3: Sliding Window
Q3_Sliding_Window/sliding_sender: Q3_Sliding_Window/sliding_sender.c
	$(CC) $(CFLAGS) $< -o $@

Q3_Sliding_Window/sliding_receiver: Q3_Sliding_Window/sliding_receiver.c
	$(CC) $(CFLAGS) $< -o $@

# Q4: Go Back N
Q4_Go_Back_N/gbn_sender: Q4_Go_Back_N/gbn_sender.c
	$(CC) $(CFLAGS) $< -o $@

Q4_Go_Back_N/gbn_receiver: Q4_Go_Back_N/gbn_receiver.c
	$(CC) $(CFLAGS) $< -o $@

# Q5: Selective Repeat
Q5_Selective_Repeat/sr_sender: Q5_Selective_Repeat/sr_sender.c
	$(CC) $(CFLAGS) $< -o $@

Q5_Selective_Repeat/sr_receiver: Q5_Selective_Repeat/sr_receiver.c
	$(CC) $(CFLAGS) $< -o $@

# Q6: Error Control
Q6_Error_Control/crc: Q6_Error_Control/crc.c
	$(CC) $(CFLAGS) $< -o $@

Q6_Error_Control/hamming: Q6_Error_Control/hamming.c
	$(CC) $(CFLAGS) $< -o $@

# Clean all executables
clean:
	rm -f Q1_Stop_Wait/sender Q1_Stop_Wait/receiver
	rm -f Q2_Stop_Wait_ARQ/sender_arq Q2_Stop_Wait_ARQ/receiver_arq
	rm -f Q3_Sliding_Window/sliding_sender Q3_Sliding_Window/sliding_receiver
	rm -f Q4_Go_Back_N/gbn_sender Q4_Go_Back_N/gbn_receiver
	rm -f Q5_Selective_Repeat/sr_sender Q5_Selective_Repeat/sr_receiver
	rm -f Q6_Error_Control/crc Q6_Error_Control/hamming

# Display help
help:
	@echo "Socket Programming Lab Makefile"
	@echo "================================"
	@echo ""
	@echo "Available targets:"
	@echo "  make              - Build all projects"
	@echo "  make all          - Build all projects"
	@echo "  make clean        - Remove all compiled executables"
	@echo "  make help         - Show this help message"
	@echo ""
	@echo "Quick run examples:"
	@echo "  ./Q1_Stop_Wait/sender"
	@echo "  ./Q1_Stop_Wait/receiver"
	@echo "  ./Q2_Stop_Wait_ARQ/sender_arq"
	@echo "  etc..."
