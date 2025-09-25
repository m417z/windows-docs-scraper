typedef struct _MARK_HANDLE_INFO32 {
  union {
    DWORD UsnSourceInfo;
    DWORD CopyNumber;
  } DUMMYUNIONNAME;
  DWORD  UsnSourceInfo;
  UINT32 VolumeHandle;
  DWORD  HandleInfo;
} MARK_HANDLE_INFO32, *PMARK_HANDLE_INFO32;