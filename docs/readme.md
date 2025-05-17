# 🎵 SLRC SPOTIFY-JSON to LRC Converter

![C Version](https://img.shields.io/badge/C-17-blue)
![Status](https://img.shields.io/badge/status-stable-green)

A **SPOTIFY-JSON to LRC Converter** is a lightweight tool that converts **Spotify-synced lyrics** from JSON format to the **LRC (Lyrics) format**, making it compatible with various media players and karaoke software.

## 🛠️ Installation & Compilation

### **1️⃣ Dependencies**

```sh
Jansson library
```

### **2️⃣ Compile the Project with mingw64**

Run the following command in your terminal slrc-c folder:

```sh
gcc -o slrc main.c converter.c -I/mingw64/include -L/mingw64/lib -ljansson -std=c17 -Wall -Wextra -pedantic -Werror
```

---

**Obs**: You can find python version too in slrc-py folder

---

### **Extracting Lyrics from Spotify**

1. Follow the method in this [YouTube video](https://youtu.be/NX1tSSz20Uo?si=vFeLizY2HvwFGOrK) up to **minute 1:20**.
2. Extract the lyrics **manually** and save them as a JSON file (e.g., `lyrics.json`).

### **Running the Converter**

```sh
./slrc lyrics.json > output.lrc
```

---

**Obs**: There is a compiled exe in slrc-c/bin folder if you want to use it. 

---

The output file will contain the lyrics formatted with timestamps, ready for use in **LRC-compatible** music players.

### **Example Output**

```plaintext
[00:34.760] I'm on fire
[00:38.210] My emotions run so deep
[00:42.770] You vowed to love me
[00:46.730] Is that a vow you'd keep?
...
```

---

## 📝 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---
