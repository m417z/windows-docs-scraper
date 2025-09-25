typedef struct _D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN {
  D3DKMT_ALIGN64 ULONG64   hPrivateData;
  D3DKMT_ALIGN64 ULONGLONG PresentAtQpc;
  union {
    struct {
      UINT Discard : 1;
      UINT PresentAt : 1;
      UINT hPrivateDataIsPointer : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  } Flags;
} D3DKMT_FLIPMANAGER_PRESENTHISTORYTOKEN;