typedef struct _MARK_HANDLE_INFO32 {
  union {
    ULONG UsnSourceInfo;
    ULONG CopyNumber;
  } DUMMYUNIONNAME;
  ULONG  UsnSourceInfo;
  UINT32 VolumeHandle;
  ULONG  HandleInfo;
} MARK_HANDLE_INFO32, *PMARK_HANDLE_INFO32;