#include "SDCardInfo.h"

SDCardInfo::SDCardInfo(uint8_t pinCS) {
    _pinCS = pinCS;
}

bool SDCardInfo::checkInfoCard() {
    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.println(F("\nInitializing SD card..."));
    #endif

    // Check Init Card
    _sdInfo.isInitCard = SDCardInfo::_card.init(SPI_HALF_SPEED, _pinCS);

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Init Card = "));
        Monitor.println(_sdInfo.isInitCard);
    #endif

    if (!_sdInfo.isInitCard) {
        return false;
    }

    // Get Card Type
    switch (SDCardInfo::_card.type()) {
        case SD_CARD_TYPE_SD1:
            _sdInfo.type = "SD1";
            break;
        case SD_CARD_TYPE_SD2:
            _sdInfo.type = "SD2";
            break;
        case SD_CARD_TYPE_SDHC:
            _sdInfo.type = "SDHC";
            break;
        default:
            _sdInfo.type = "Unknown";
            break;
    }

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Card type = "));
        Monitor.println(_sdInfo.type);
    #endif

    // Check Init Volume
    _sdInfo.isInitVolume = SDCardInfo::_volume.init(SDCardInfo::_card);

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Init Volume = "));
        Monitor.println(_sdInfo.isInitVolume);
    #endif

    if (!_sdInfo.isInitVolume) {
        return false;
    }

    // Get Clusters
    _sdInfo.clusterCount = SDCardInfo::_volume.clusterCount();

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Clusters = "));
        Monitor.println(_sdInfo.clusterCount);
    #endif

    // Get Blocks x Cluster
    _sdInfo.blocksPerCluster = SDCardInfo::_volume.blocksPerCluster();

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Blocks x Cluster = "));
        Monitor.println(_sdInfo.blocksPerCluster);
    #endif

    // Get Total Blocks
    _sdInfo.totalBlocks = _sdInfo.clusterCount * _sdInfo.blocksPerCluster;

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Total Blocks = "));
        Monitor.println(_sdInfo.totalBlocks);
    #endif

    // Get Volume type
    _sdInfo.fatType = SDCardInfo::_volume.fatType();

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Volume type = FAT"));
        Monitor.println(_sdInfo.fatType);
    #endif

    // Get Volume size (KB)
    _sdInfo.volumesizeKB = _sdInfo.totalBlocks/2;

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Volume size (KB) = "));
        Monitor.println(_sdInfo.volumesizeKB);
    #endif

    // Get Volume size (MB)
    _sdInfo.volumesizeMB = _sdInfo.volumesizeKB/1024;

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Volume size (MB) = "));
        Monitor.println(_sdInfo.volumesizeMB);
    #endif

    // Get Volume size (GB)
    _sdInfo.volumesizeGB = _sdInfo.volumesizeMB/1024.0;

    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.print(F("Volume size (GB) = "));
        Monitor.println(_sdInfo.volumesizeGB);
    #endif

    printList();

    return true;
}

// Start Card Info
bool SDCardInfo::isInitCard() {
    return _sdInfo.isInitCard;
}

String SDCardInfo::getType() {
    return _sdInfo.type;
}

bool SDCardInfo::isInitVolume() {
    return _sdInfo.isInitVolume;
}

uint32_t SDCardInfo::getClusterCount() {
    return _sdInfo.clusterCount;
}

uint32_t SDCardInfo::getBlocksPerCluster() {
    return _sdInfo.blocksPerCluster;
}

uint32_t SDCardInfo::getTotalBlocks() {
    return _sdInfo.totalBlocks;
}

unsigned char SDCardInfo::getFatType() {
    return _sdInfo.fatType;
}

uint32_t SDCardInfo::getVolumesizeKB() {
    return _sdInfo.volumesizeKB;
}

uint32_t SDCardInfo::getVolumesizeMB() {
    return _sdInfo.volumesizeMB;
}

float SDCardInfo::getVolumesizeGB() {
    return _sdInfo.volumesizeGB;
}
// !End Card Info

void SDCardInfo::printList() {
    #ifdef __DEBUG_MONITOR_SERIAL__
        Monitor.println(F("\nFiles found on the card (name, date and size in bytes)"));
    #endif

    SDCardInfo::_root.openRoot(SDCardInfo::_volume);
    SDCardInfo::_root.ls(LS_R | LS_DATE | LS_SIZE);
}
