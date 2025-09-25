typedef struct _REPARSE_GUID_DATA_BUFFER {
  ULONG  ReparseTag;
  USHORT ReparseDataLength;
  USHORT Reserved;
  GUID   ReparseGuid;
  struct {
    UCHAR DataBuffer[1];
  } GenericReparseBuffer;
} REPARSE_GUID_DATA_BUFFER, *PREPARSE_GUID_DATA_BUFFER;