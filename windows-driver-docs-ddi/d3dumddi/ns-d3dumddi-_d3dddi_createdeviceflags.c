typedef struct _D3DDDI_CREATEDEVICEFLAGS {
  union {
    struct {
      UINT AllowMultithreading : 1;
      UINT AllowFlipBatching : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DDDI_CREATEDEVICEFLAGS;