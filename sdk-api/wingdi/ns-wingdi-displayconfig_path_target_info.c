typedef struct DISPLAYCONFIG_PATH_TARGET_INFO {
  LUID                                  adapterId;
  UINT32                                id;
  union {
    UINT32 modeInfoIdx;
    struct {
      UINT32 desktopModeInfoIdx : 16;
      UINT32 targetModeInfoIdx : 16;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY outputTechnology;
  DISPLAYCONFIG_ROTATION                rotation;
  DISPLAYCONFIG_SCALING                 scaling;
  DISPLAYCONFIG_RATIONAL                refreshRate;
  DISPLAYCONFIG_SCANLINE_ORDERING       scanLineOrdering;
  BOOL                                  targetAvailable;
  UINT32                                statusFlags;
} DISPLAYCONFIG_PATH_TARGET_INFO;