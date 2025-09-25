typedef struct _MARK_HANDLE_INFO {
  union {
    DWORD UsnSourceInfo;
    DWORD CopyNumber;
  } DUMMYUNIONNAME;
  DWORD  UsnSourceInfo;
  HANDLE VolumeHandle;
  DWORD  HandleInfo;
} MARK_HANDLE_INFO, *PMARK_HANDLE_INFO;