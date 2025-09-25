typedef struct _FS_BPIO_OUTPUT {
  FS_BPIO_OPERATIONS Operation;
  FS_BPIO_OUTFLAGS   OutFlags;
  ULONGLONG          Reserved1;
  ULONGLONG          Reserved2;
  union {
    FS_BPIO_RESULTS Enable;
    FS_BPIO_RESULTS Query;
    FS_BPIO_RESULTS VolumeStackResume;
    FS_BPIO_RESULTS StreamResume;
    FS_BPIO_INFO    GetInfo;
  };
} FS_BPIO_OUTPUT, *PFS_BPIO_OUTPUT;