#include "SDStorage.h"

SDStorage::SDStorage(uint8_t mode) {
    _mode = mode;
}

bool SDStorage::checkStatusInitCard(uint8_t pinCS) {
    if (SD.begin(pinCS)) {
        _statusInitCard = true;
    } else {
        _statusInitCard = false;
    }
    return _statusInitCard;
}

bool SDStorage::getStatusInitCard() {
    return _statusInitCard;
}

void SDStorage::_writeData(String data) {
    SDStorage::_myFile.println(data);
}

bool SDStorage::writeData(const String &filename, String data) {
    if (_statusInitCard) {
        SDStorage::_myFile = SD.open(filename, _mode);
        if (SDStorage::_myFile) {
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

bool SDStorage::readData(const String &filename) {
    _data = "";
    if (_statusInitCard) {
        SDStorage::_myFile = SD.open(filename);
        if (SDStorage::_myFile) {
            while (SDStorage::_myFile.available()) {
              _data = SDStorage::_myFile.readString();
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

void SDStorage::closeFile() {
    SDStorage::_myFile.close();
}

String SDStorage::getData() {
    Serial.println(_data.length());
    return _data.substring(0, _data.length() - 2);
}

void SDStorage::removeFile(const String &filename) {
    SD.remove(filename);
}
