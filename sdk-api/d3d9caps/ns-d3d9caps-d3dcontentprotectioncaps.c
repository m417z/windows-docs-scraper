typedef struct _D3DCONTENTPROTECTIONCAPS {
  DWORD     Caps;
  GUID      KeyExchangeType;
  UINT      BufferAlignmentStart;
  UINT      BlockAlignmentSize;
  ULONGLONG ProtectedMemorySize;
} D3DCONTENTPROTECTIONCAPS;