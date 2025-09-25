typedef struct _D3DKMT_QUERYSTATISTICS_ADAPTER_INFORMATION_FLAGS {
  union {
    struct {
      UINT64 NumberOfMemoryGroups : 2;
      UINT64 SupportsDemotion : 1;
      UINT64 Reserved : 61;
    };
    D3DKMT_ALIGN64 UINT64 Value;
  };
} D3DKMT_QUERYSTATISTICS_ADAPTER_INFORMATION_FLAGS;