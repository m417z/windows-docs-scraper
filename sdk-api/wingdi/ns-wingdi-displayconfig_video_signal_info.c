typedef struct DISPLAYCONFIG_VIDEO_SIGNAL_INFO {
  UINT64                          pixelRate;
  DISPLAYCONFIG_RATIONAL          hSyncFreq;
  DISPLAYCONFIG_RATIONAL          vSyncFreq;
  DISPLAYCONFIG_2DREGION          activeSize;
  DISPLAYCONFIG_2DREGION          totalSize;
  union {
    struct {
      UINT32 videoStandard : 16;
      UINT32 vSyncFreqDivider : 6;
      UINT32 reserved : 10;
    } AdditionalSignalInfo;
    UINT32 videoStandard;
  } DUMMYUNIONNAME;
  DISPLAYCONFIG_SCANLINE_ORDERING scanLineOrdering;
} DISPLAYCONFIG_VIDEO_SIGNAL_INFO;