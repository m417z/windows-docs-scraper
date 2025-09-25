typedef struct _D3DKMT_WDDM_3_1_CAPS {
  union {
    struct {
      UINT NativeGpuFenceSupported : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} D3DKMT_WDDM_3_1_CAPS;