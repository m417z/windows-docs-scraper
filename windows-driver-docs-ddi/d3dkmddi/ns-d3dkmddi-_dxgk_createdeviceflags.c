typedef struct _DXGK_CREATEDEVICEFLAGS {
  union {
    struct {
      UINT SystemDevice : 1;
      UINT GdiDevice : 1;
      UINT Reserved : 29;
      UINT DXGK_DEVICE_RESERVED0 : 1;
    };
    UINT Value;
  };
} DXGK_CREATEDEVICEFLAGS;