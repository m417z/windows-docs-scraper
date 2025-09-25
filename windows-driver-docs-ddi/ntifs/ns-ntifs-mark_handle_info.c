typedef struct _MARK_HANDLE_INFO {
  union {
    ULONG UsnSourceInfo;
    ULONG CopyNumber;
  } DUMMYUNIONNAME;
  ULONG  UsnSourceInfo;
  HANDLE VolumeHandle;
  ULONG  HandleInfo;
} MARK_HANDLE_INFO, *PMARK_HANDLE_INFO;