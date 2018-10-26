#include <Arduino.h>
#include "SDCardInfo.h"
#include "SDStorage.h"
#include "Configuration.h"

SDCardInfo _SDCardInfo(__CS_PIN__);
SDStorage _SDStorage(FILE_WRITE);

void setup() {
    SerialMonitor.begin(__BAUDRATE__);

    if (_SDCardInfo.checkInfoCard()) {
        SerialMonitor.println(F("\n-->Success!"));
    }

    if (_SDStorage.checkStatusInitCard(__CS_PIN__)) {
        SerialMonitor.println(F("\n-->Success!"));
        // _SDStorage.removeFile(__FILE_DATA_LOGGER__);
    }

    bool isWriteData = _SDStorage.writeData(__FILE_DATA_LOGGER__, "Update!!!");
    if (isWriteData) {
        SerialMonitor.println(F("\n-->Writing Success!"));
    } else {
        SerialMonitor.println(F("\n-->Writing Fail!"));
    }

    bool isReadData = _SDStorage.readData(__FILE_DATA_LOGGER__);
    if (isReadData) {
        SerialMonitor.println(F("\n-->Start Reading!"));
        String data = _SDStorage.getData();
        SerialMonitor.println(data);
        SerialMonitor.println(F("\n-->Reading Success!"));
    } else {
        SerialMonitor.println(F("\n-->Reading Fail!"));
    }
}

void loop() {

}
