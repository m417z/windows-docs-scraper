typedef struct _REPARSE_DATA_BUFFER_EX {
  ULONG     Flags;
  ULONG     ExistingReparseTag;
  GUID      ExistingReparseGuid;
  ULONGLONG Reserved;
  union {
    REPARSE_DATA_BUFFER      ReparseDataBuffer;
    REPARSE_GUID_DATA_BUFFER ReparseGuidDataBuffer;
  } DUMMYUNIONNAME;
} REPARSE_DATA_BUFFER_EX, *PREPARSE_DATA_BUFFER_EX;