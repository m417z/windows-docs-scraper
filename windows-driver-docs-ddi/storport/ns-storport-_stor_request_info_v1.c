typedef struct _STOR_REQUEST_INFO_V1 {
  USHORT                Version;
  USHORT                Size;
  STOR_IO_PRIORITY_HINT PriorityHint;
  ULONG                 Flags;
  ULONG                 Key;
  ULONG                 Length;
  BOOLEAN               IsWriteRequest;
  UCHAR                 Reserved[3];
} STOR_REQUEST_INFO_V1, *PSTOR_REQUEST_INFO_V1;