typedef struct D3DDDI_EVICT_FLAGS {
  union {
    struct {
      UINT EvictOnlyIfNecessary : 1;
      UINT NotWrittenTo : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_EVICT_FLAGS;