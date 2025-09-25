typedef struct _D3DDDI_OPENRESOURCEFLAGS {
  union {
    struct {
      UINT Fullscreen : 1;
      UINT AlphaOverride : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_OPENRESOURCEFLAGS;