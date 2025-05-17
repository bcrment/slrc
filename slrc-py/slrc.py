import json
import os

def format_time(ms):
    minutes = ms // 60000
    seconds = (ms % 60000) // 1000
    milliseconds = ms % 1000
    return f"[{minutes:02}:{seconds:02}.{milliseconds:03}]"

filename = "lyric.json"

script_dir = os.path.dirname(os.path.abspath(__file__))
file_path = os.path.join(script_dir, filename)

try:
    with open(file_path, "r", encoding="utf-8") as file:
        data = json.load(file)

    if "lyrics" in data and "lines" in data["lyrics"]:
        lines = data["lyrics"]["lines"]
        for line in lines:
            start_time_ms = int(line["startTimeMs"])
            words = line["words"]
            print(f"{format_time(start_time_ms)} {words}")
    else:
        print("Err: 'lines' keys not found in JSON")
except FileNotFoundError:
    print(f"Err: file '{filename}' not found in '{script_dir}'")
except json.JSONDecodeError:
    print(f"Err: not possble to decode file '{filename}' as JSON")
