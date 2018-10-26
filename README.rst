#################################################
Thư viện lưu trữ dữ liệu trên SD Card với Arduino
#################################################

:Info: Github <https://github.com/thiminhnhut/ArduinoDueSDCard>
:Author: Thi Minh Nhựt <thiminhnhut@gmail.com>
:Date: $Date: 26/10/2018 $
:Revision: $Revision: 1.0.0 $
:Description: Thư viện lưu trữ dữ liệu trên SD Card với Arduino

=============================================================================

.. sectnum::

.. contents:: Nội dung

=============================================================================

Nội dung thực hiện
******************

Thư viện ArduinoDueSDCard
=============================

* Thư mục source: `src <https://github.com/thiminhnhut/ArduinoDueSDCard/blob/master/src>`_.

  * File `SDCardInfo.h <https://github.com/thiminhnhut/ArduinoDueSDCard/blob/master/src/SDCardInfo.h>`_:

  .. code::

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

  * File `SDCardInfo.cpp <https://github.com/thiminhnhut/ArduinoDueSDCard/blob/master/src/SDCardInfo.cpp>`_.

  * File `SDStorage.h <https://github.com/thiminhnhut/ArduinoDueSDCard/blob/master/src/SDStorage.h>`_:

  .. code::

    SDStorage(uint8_t mode);

    bool checkStatusInitCard(uint8_t pinCS);

    bool getStatusInitCard();

    bool writeData(const String &filename, String data);

    bool readData(const String &filename);

    String getData();

    void removeFile(const String &filename);

* Ví dụ: `demo.ino <https://github.com/thiminhnhut/ArduinoDueSDCard/blob/master/examples/demo/demo.ino>`_

Chức năng của thư viện ArduinoDueSDCard
=======================================

* Xem thông tin của SD Card.

* Lưu trữ thông tin vào SD Card.
