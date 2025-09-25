typedef struct _D3DKMT_DEVICERESET_STATE {
  union {
    struct {
      UINT DesktopSwitched : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DKMT_DEVICERESET_STATE;