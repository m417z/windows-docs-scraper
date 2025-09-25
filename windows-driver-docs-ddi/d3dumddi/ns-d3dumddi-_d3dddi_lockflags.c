typedef struct _D3DDDI_LOCKFLAGS {
  union {
    struct {
      UINT ReadOnly : 1;
      UINT WriteOnly : 1;
      UINT NoOverwrite : 1;
      UINT Discard : 1;
      UINT RangeValid : 1;
      UINT AreaValid : 1;
      UINT BoxValid : 1;
      UINT NotifyOnly : 1;
      UINT MightDrawFromLocked : 1;
      UINT DoNotWait : 1;
      UINT Reserved : 22;
    };
    UINT Value;
  };
} D3DDDI_LOCKFLAGS;