#include "SDStore.h"

SDStore::SDStore(uint8_t mode, uint8_t pinCS) {
    _mode = mode;
    _pinCS = pinCS;
}

bool SDStore::checkStatusInitCard() {
    if (SD.begin(_pinCS)) {
        _statusInitCard = true;
    } else {
        _statusInitCard = false;
    }
    return _statusInitCard;
}

bool SDStore::getStatusInitCard() {
    return _statusInitCard;
}

void SDStore::_writeData(String data) {
    SDStore::_myFile.println(data);
}

bool SDStore::writeData(const String &filename, String data) {
    if (_statusInitCard) {
        SDStore::_myFile = SD.open(filename, _mode);
        if (SDStore::_myFile) {
            _writeData(data);
            closeFile();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool SDStore::readData(const String &filename) {
    _data = "";
    if (_statusInitCard) {
        SDStore::_myFile = SD.open(filename);
        if (SDStore::_myFile) {
            while (SDStore::_myFile.available()) {
              _data = SDStore::_myFile.readString();
            }
            closeFile();
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void SDStore::closeFile() {
    SDStore::_myFile.close();
}

String SDStore::getData() {
    Serial.println(_data.length());
    return _data.substring(0, _data.length() - 2);
}

void SDStore::removeFile(const String &filename) {
    SD.remove(filename);
}
