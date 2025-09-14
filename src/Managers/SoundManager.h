#pragma once
#include "ofMain.h"
using namespace std;

class SoundManager {
    public:
        inline static map<string, ofSoundPlayer> sounds;

        // Functions
        static void loadSong(const string &name, string path) {
            ofSoundPlayer sound;
            if (sound.load(path)) {sounds[name] = sound;}
        }

        static void playSong(const string &name, bool loop) {
            auto it = sounds.find(name);
            if (it != sounds.end()) {
                it->second.setLoop(loop);
                it->second.play();
            }
        }

        static void stopSong(const string &name) {
            auto it = sounds.find(name);
            if (it != sounds.end()) {it->second.stop();}
        }

        static void setVolume(const string &name, double volume) {
            auto it = sounds.find(name);
            if (it != sounds.end()) {it->second.setVolume(volume);}
        }

        static void loadSongs() {
            Settings::readSettings();

            loadSong("buttonClick", "sounds/buttonClick.ogg");
            loadSong("shine", "sounds/shine.wav");
            loadSong("bounce", "sounds/bounce.wav");

            if (Settings::settings["theme"] == "1") {loadSong("song", "sounds/classicSong.wav");}
            else if (Settings::settings["theme"] == "2") {loadSong("song", "sounds/factorySong.wav");}
            else {
                vector<string> extensions = {".mp3", ".wav", ".aiff", ".ogg"};
                for (string ext: extensions) {
                    if (ofFile::doesFileExist("sounds/defaultSong"+ext)) {
                        loadSong("song", "sounds/defaultSong"+ext);
                        break;
                    }
                }
            }
        }
};