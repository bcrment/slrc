#ifndef CONVERTER_H
#define CONVERTER_H

#include <stdbool.h>

// Converts milliseconds to "mm:ss.ms" format
void convert_time_ms(int ms, char *buffer, size_t buffer_size);

// Processes the JSON file and prints formatted lyrics
bool process_lyrics(const char *filename);

#endif // CONVERTER_H
