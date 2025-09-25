typedef struct _FILE_LOCK_INFO {
  LARGE_INTEGER StartingByte;
  LARGE_INTEGER Length;
  BOOLEAN       ExclusiveLock;
  ULONG         Key;
  PFILE_OBJECT  FileObject;
  PVOID         ProcessId;
  LARGE_INTEGER EndingByte;
} FILE_LOCK_INFO;