typedef struct _D3DKMT_WDDM_2_7_CAPS {
  union {
    struct {
      UINT HwSchSupported : 1;
      UINT HwSchEnabled : 1;
      UINT HwSchEnabledByDefault : 1;
      UINT IndependentVidPnVSyncControl : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} D3DKMT_WDDM_2_7_CAPS;