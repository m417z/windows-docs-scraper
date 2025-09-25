typedef struct DISPLAYCONFIG_TARGET_DEVICE_NAME {
  DISPLAYCONFIG_DEVICE_INFO_HEADER       header;
  DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS flags;
  DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY  outputTechnology;
  UINT16                                 edidManufactureId;
  UINT16                                 edidProductCodeId;
  UINT32                                 connectorInstance;
  WCHAR                                  monitorFriendlyDeviceName[64];
  WCHAR                                  monitorDevicePath[128];
} DISPLAYCONFIG_TARGET_DEVICE_NAME;