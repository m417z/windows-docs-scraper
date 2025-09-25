typedef struct DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS {
  union {
    struct {
      UINT32 friendlyNameFromEdid : 1;
      UINT32 friendlyNameForced : 1;
      UINT32 edidIdsValid : 1;
      UINT32 reserved : 29;
    } DUMMYSTRUCTNAME;
    UINT32 value;
  } DUMMYUNIONNAME;
} DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS;