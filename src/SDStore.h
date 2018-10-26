#ifndef SDStore_h
#define SDStore_h

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDStore {
private:
    File _myFile;

    uint8_t _mode;

    bool _statusInitCard = false;

    String _data;

    void _writeData(String data);
public:
    SDStore(uint8_t mode);

    bool checkStatusInitCard(uint8_t pinCS);

    bool getStatusInitCard();

    bool writeData(const String &filename, String data);

    bool readData(const String &filename);

    void closeFile();

    String getData();

    void removeFile(const String &filename);
};
#endif
