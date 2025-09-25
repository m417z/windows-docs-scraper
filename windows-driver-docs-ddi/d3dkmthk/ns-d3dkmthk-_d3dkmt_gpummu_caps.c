typedef struct _D3DKMT_GPUMMU_CAPS {
  union {
    struct {
      UINT ReadOnlyMemorySupported : 1;
      UINT NoExecuteMemorySupported : 1;
      UINT CacheCoherentMemorySupported : 1;
      UINT Reserved : 29;
    };
    UINT Value;
  } Flags;
  UINT  VirtualAddressBitCount;
} D3DKMT_GPUMMU_CAPS;