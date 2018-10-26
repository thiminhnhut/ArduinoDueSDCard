#include <Arduino.h>
#include "SDCardInfo.h"
#include "SDStore.h"
#include "Configuration.h"

SDCardInfo _SDCardInfo(__CS_PIN__);
SDStore _SDStore(FILE_WRITE, __CS_PIN__);

void setup() {
    SerialMonitor.begin(__BAUDRATE__);

    if (_SDCardInfo.checkInfoCard()) {
        SerialMonitor.println(F("\n-->Success!"));
    }

    if (_SDStore.checkStatusInitCard()) {
        SerialMonitor.println(F("\n-->Success!"));
        // _SDStore.removeFile(__FILE_DATA_LOGGER__);
    }

    bool isWriteData = _SDStore.writeData(__FILE_DATA_LOGGER__, "Update!!!");
    if (isWriteData) {
        SerialMonitor.println(F("\n-->Writing Success!"));
    } else {
        SerialMonitor.println(F("\n-->Writing Fail!"));
    }

    bool isReadData = _SDStore.readData(__FILE_DATA_LOGGER__);
    if (isReadData) {
        SerialMonitor.println(F("\n-->Start Reading!"));
        String data = _SDStore.getData();
        SerialMonitor.println(data);
        SerialMonitor.println(F("\n-->Reading Success!"));
    } else {
        SerialMonitor.println(F("\n-->Reading Fail!"));
    }
}

void loop() {

}
