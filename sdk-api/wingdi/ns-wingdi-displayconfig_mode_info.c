typedef struct DISPLAYCONFIG_MODE_INFO {
  DISPLAYCONFIG_MODE_INFO_TYPE infoType;
  UINT32                       id;
  LUID                         adapterId;
  union {
    DISPLAYCONFIG_TARGET_MODE        targetMode;
    DISPLAYCONFIG_SOURCE_MODE        sourceMode;
    DISPLAYCONFIG_DESKTOP_IMAGE_INFO desktopImageInfo;
  } DUMMYUNIONNAME;
} DISPLAYCONFIG_MODE_INFO;