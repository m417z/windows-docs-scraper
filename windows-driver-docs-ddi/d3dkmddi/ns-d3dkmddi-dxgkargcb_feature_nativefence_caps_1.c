typedef struct _DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1 {
  union {
    struct {
      UINT SupportOptimizedDefaultFenceType : 1;
      UINT SupportIntraGpuFenceType : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGKARGCB_FEATURE_NATIVEFENCE_CAPS_1;