typedef struct _D3DKMT_WDDM_3_0_CAPS {
  union {
    struct {
      UINT HwFlipQueueSupportState : 2;
      UINT HwFlipQueueEnabled : 1;
      UINT DisplayableSupported : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} D3DKMT_WDDM_3_0_CAPS;