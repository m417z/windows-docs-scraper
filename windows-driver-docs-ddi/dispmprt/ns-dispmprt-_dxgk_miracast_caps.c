typedef struct _DXGK_MIRACAST_CAPS {
  ULONG MaxChunkPrivateDriverDataSize;
  union {
    struct {
      UINT HdcpSupport : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  } Flags;
} DXGK_MIRACAST_CAPS, *PDXGK_MIRACAST_CAPS;