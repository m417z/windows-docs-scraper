typedef struct _D3DDDI_FLIPOVERLAYFLAGS {
  union {
    struct {
      UINT Even : 1;
      UINT Odd : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_FLIPOVERLAYFLAGS;