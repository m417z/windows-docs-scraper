typedef struct _DXGK_DIRTY_BIT_TRACKING_CAPS {
  union {
    struct {
      UINT32 DirtyBitTrackingSupported : 1;
      UINT32 DirtyBitTrackingPerformant : 1;
      UINT32 Reserved : 30;
    };
    UINT32 Value;
  };
} DXGK_DIRTY_BIT_TRACKING_CAPS;