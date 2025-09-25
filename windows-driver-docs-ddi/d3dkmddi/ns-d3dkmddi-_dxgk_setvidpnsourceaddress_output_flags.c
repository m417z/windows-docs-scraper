typedef struct _DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS {
  union {
    struct {
      UINT PrePresentNeeded : 1;
      UINT HwFlipQueueDrainNeeded : 1;
      UINT HwFlipQueueDrainAllPlanes : 1;
      UINT HwFlipQueueDrainAllSources : 1;
#if ...
      UINT Reserved : 28;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS;