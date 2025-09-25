typedef struct _D3DDDI_RESOURCEFLAGS2 {
  union {
    struct {
      UINT VideoEncoder : 1;
      UINT UserMemory : 1;
      UINT CrossAdapter : 1;
      UINT IsDisplayable : 1;
#if ...
      UINT Reserved : 28;
#elif
      UINT Reserved : 29;
#else
      UINT Reserved : 30;
#endif
    };
    UINT Value;
  };
} D3DDDI_RESOURCEFLAGS2;