typedef struct _D3DDDI_LOCKASYNCFLAGS {
  union {
    struct {
      UINT NoOverwrite : 1;
      UINT Discard : 1;
      UINT RangeValid : 1;
      UINT AreaValid : 1;
      UINT BoxValid : 1;
      UINT NoExistingReferences : 1;
      UINT NotifyOnly : 1;
      UINT Reserved : 25;
    };
    UINT Value;
  };
} D3DDDI_LOCKASYNCFLAGS;