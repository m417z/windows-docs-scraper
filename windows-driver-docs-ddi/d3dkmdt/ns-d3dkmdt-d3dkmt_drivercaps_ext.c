typedef struct _D3DKMT_DRIVERCAPS_EXT {
  union {
    struct {
      UINT VirtualModeSupport : 1;
      UINT Usb4MonitorSupport : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} D3DKMT_DRIVERCAPS_EXT;