#include <stdio.h>
#include <stdlib.h>
#include <jansson.h>
#include "converter.h"

#define TIME_FORMAT_SIZE 10  // "mm:ss.ms" -> 9 chars + '\0'

// Converts milliseconds to "mm:ss.ms" format
void convert_time_ms(int ms, char *buffer, size_t buffer_size) {
    int minutes = ms / 60000;
    int seconds = ms % 60000 / 1000;
    int milliseconds = ms % 1000;
    
    snprintf(buffer, buffer_size, "%02d:%02d.%03d", minutes, seconds, milliseconds);
}

// Reads and processes the JSON file
bool process_lyrics(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Cannot open file '%s'.\n", filename);
        return false;
    }

    json_error_t error;
    json_t *root = json_loadf(file, 0, &error);
    fclose(file);

    if (!root) {
        fprintf(stderr, "JSON Error: %s\n", error.text);
        return false;
    }

    json_t *lyrics = json_object_get(root, "lyrics");
    if (!json_is_object(lyrics)) {
        fprintf(stderr, "Error: Invalid JSON format.\n");
        json_decref(root);
        return false;
    }

    json_t *lines = json_object_get(lyrics, "lines");
    if (!json_is_array(lines)) {
        fprintf(stderr, "Error: Missing or invalid 'lines' structure in JSON.\n");
        json_decref(root);
        return false;
    }

    size_t index;
    json_t *line;
    char time_buffer[TIME_FORMAT_SIZE];

    json_array_foreach(lines, index, line) {
        json_t *startTimeMs = json_object_get(line, "startTimeMs");
        json_t *words = json_object_get(line, "words");

        if (!json_is_string(startTimeMs) || !json_is_string(words)) {
            continue; // Skip invalid entries
        }

        int ms = atoi(json_string_value(startTimeMs));
        convert_time_ms(ms, time_buffer, sizeof(time_buffer));

        printf("[%s] %s\n", time_buffer, json_string_value(words));
    }

    json_decref(root);
    return true;
}