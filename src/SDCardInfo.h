#ifndef SDCard_h
#define SDCard_h

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define __DEBUG_MONITOR_SERIAL__
#ifdef __DEBUG_MONITOR_SERIAL__
#define Monitor Serial
#endif

class SDCardInfo {
private:
    struct SDInfo {
        bool isInitCard;
        String type;
        bool isInitVolume;
        uint32_t clusterCount;
        uint32_t blocksPerCluster;
        uint32_t totalBlocks;
        unsigned char fatType;
        uint32_t volumesizeKB;
        uint32_t volumesizeMB;
        float volumesizeGB;
    };

    Sd2Card _card;
    SdVolume _volume;
    SdFile _root;

    uint8_t _pinCS;

    SDInfo _sdInfo;

public:
    SDCardInfo(uint8_t pinCS);

    bool checkInfoCard();

    // Start Card Info
    bool isInitCard();

    String getType();

    bool isInitVolume();

    uint32_t getClusterCount();

    uint32_t getBlocksPerCluster();

    uint32_t getTotalBlocks();

    unsigned char getFatType();

    uint32_t getVolumesizeKB();

    uint32_t getVolumesizeMB();

    float getVolumesizeGB();
    // !End Card Info

    void printList();
};
#endif
