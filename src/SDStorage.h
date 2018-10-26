#ifndef SDStorage_h
#define SDStorage_h

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

class SDStorage {
private:
    File _myFile;

    uint8_t _mode;

    bool _statusInitCard = false;

    String _data;

    void _writeData(String data);

    void _closeFile();
public:
    SDStorage(uint8_t mode);

    bool checkStatusInitCard(uint8_t pinCS);

    bool getStatusInitCard();

    bool writeData(const String &filename, String data);

    bool readData(const String &filename);

    String getData();

    void removeFile(const String &filename);
};
#endif
