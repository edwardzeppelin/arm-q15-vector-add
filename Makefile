CC = gcc
CFLAGS = -O2 -mcpu=cortex-a53 -mfpu=neon -mfloat-abi=hard -Wall
TARGET = vector_q15_test
SOURCES = add_vector_q15.c add_vector_q15_ref.c add_vector_q15_fast.c add_vector_q15_tb.c
HEADERS = dsp-lecture-q15.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) -lm

clean:
	rm -f $(TARGET)

test: $(TARGET)
	./$(TARGET)

.PHONY: clean test

scp -r C:/Projects/DSP/Lab1Linux guap-1245-eduard@raspberrypi2:/home/labs/