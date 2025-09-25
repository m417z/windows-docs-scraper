typedef struct _FILE_ID_GLOBAL_TX_DIR_INFORMATION {
  ULONG         NextEntryOffset;
  ULONG         FileIndex;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER EndOfFile;
  LARGE_INTEGER AllocationSize;
  ULONG         FileAttributes;
  ULONG         FileNameLength;
  LARGE_INTEGER FileId;
  GUID          LockingTransactionId;
  ULONG         TxInfoFlags;
  WCHAR         FileName[1];
} FILE_ID_GLOBAL_TX_DIR_INFORMATION, *PFILE_ID_GLOBAL_TX_DIR_INFORMATION;