typedef struct _D3DDDI_UNLOCKASYNCFLAGS {
  union {
    struct {
      UINT NotifyOnly : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DDDI_UNLOCKASYNCFLAGS;