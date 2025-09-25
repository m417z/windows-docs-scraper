typedef struct _FS_BPIO_INFO {
  ULONG  ActiveBypassIoCount;
  USHORT StorageDriverNameLen;
  WCHAR  StorageDriverName[32];
} FS_BPIO_INFO, *PFS_BPIO_INFO;