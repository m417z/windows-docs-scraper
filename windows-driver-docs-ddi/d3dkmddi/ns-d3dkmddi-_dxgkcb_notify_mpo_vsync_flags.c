typedef struct _DXGKCB_NOTIFY_MPO_VSYNC_FLAGS {
  union {
    struct {
      UINT PostPresentNeeded : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGKCB_NOTIFY_MPO_VSYNC_FLAGS;