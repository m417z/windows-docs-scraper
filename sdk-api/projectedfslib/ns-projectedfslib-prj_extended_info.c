typedef struct PRJ_EXTENDED_INFO {
  PRJ_EXT_INFO_TYPE InfoType;
  ULONG             NextInfoOffset;
  union {
    struct {
      PCWSTR TargetName;
    } Symlink;
  } DUMMYUNIONNAME;
} PRJ_EXTENDED_INFO;