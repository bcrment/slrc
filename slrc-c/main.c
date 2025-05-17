// This program converts synchronized song lyrics from Spotify in JSON format to an LRC (file format) output. 
// Using the technique in this link (https://youtu.be/NX1tSSz20Uo?si=vFeLizY2HvwFGOrK), up to minute 1:20, the lyrics can be extracted in JSON format. 
// This must be done manually.

#include <stdio.h>
#include <stdlib.h>
#include "converter.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <json_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!process_lyrics(argv[1])) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}