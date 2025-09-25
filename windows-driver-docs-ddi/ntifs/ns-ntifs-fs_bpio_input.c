typedef struct _FS_BPIO_INPUT {
  FS_BPIO_OPERATIONS Operation;
  FS_BPIO_INFLAGS    InFlags;
  ULONGLONG          Reserved1;
  ULONGLONG          Reserved2;
} FS_BPIO_INPUT, *PFS_BPIO_INPUT;