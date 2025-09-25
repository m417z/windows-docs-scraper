typedef struct DISPLAYCONFIG_PATH_SOURCE_INFO {
  LUID   adapterId;
  UINT32 id;
  union {
    UINT32 modeInfoIdx;
    struct {
      UINT32 cloneGroupId : 16;
      UINT32 sourceModeInfoIdx : 16;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  UINT32 statusFlags;
} DISPLAYCONFIG_PATH_SOURCE_INFO;