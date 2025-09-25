typedef struct _REPARSE_GUID_DATA_BUFFER {
  DWORD  ReparseTag;
  WORD   ReparseDataLength;
  WORD   Reserved;
  GUID   ReparseGuid;
  struct {
    BYTE DataBuffer[1];
  } GenericReparseBuffer;
} REPARSE_GUID_DATA_BUFFER, *PREPARSE_GUID_DATA_BUFFER;