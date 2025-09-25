typedef struct _D3DKMT_WDDM_2_9_CAPS {
  union {
    struct {
      UINT HwSchSupportState : 2;
      UINT HwSchEnabled : 1;
      UINT SelfRefreshMemorySupported : 1;
      UINT Reserved : 28;
    };
    UINT Value;
  };
} D3DKMT_WDDM_2_9_CAPS;