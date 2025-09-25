typedef struct _REARRANGE_FILE_DATA {
  ULONGLONG SourceStartingOffset;
  ULONGLONG TargetOffset;
  HANDLE    SourceFileHandle;
  ULONG     Length;
  ULONG     Flags;
} REARRANGE_FILE_DATA, *PREARRANGE_FILE_DATA;