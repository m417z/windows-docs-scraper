typedef struct _DXGK_TRACKEDWORKLOAD_STATE_FLAGS {
  union {
    struct {
      UINT Saturated : 1;
      UINT OptimalLevel : 1;
      UINT Reserved : 30;
    };
    UINT Value;
  };
} DXGK_TRACKEDWORKLOAD_STATE_FLAGS;