typedef struct _DXGK_SET_TIMING_RESULTS {
  union {
    struct {
      UINT ConnectionStatusChanges : 1;
      UINT Reserved : 31;
    };
    UINT Value;
  };
} DXGK_SET_TIMING_RESULTS, *PDXGK_SET_TIMING_RESULTS;