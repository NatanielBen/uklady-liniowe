CC = gcc

CFLAGS = -Wall -g -Iinclude

# Lista plików źródłowych ze wskazaną ścieżką src/
SRCS = src/mat_io.c src/main.c src/gauss.c src/backsubst.c

# Nazwa pliku wynikowego
TARGET = gauss

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
# Usuwa plik wykonywalny (Linux/Mac: rm, Windows z GitBash: rm też zadziała)
	rm -f $(TARGET)