typedef struct _D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS {
  union {
    struct {
      UINT HardwareQueue : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DDDI_BUILDTESTCOMMANDBUFFERFLAGS;