typedef struct DISPLAYCONFIG_TARGET_PREFERRED_MODE {
  DISPLAYCONFIG_DEVICE_INFO_HEADER header;
  UINT32                           width;
  UINT32                           height;
  DISPLAYCONFIG_TARGET_MODE        targetMode;
} DISPLAYCONFIG_TARGET_PREFERRED_MODE;