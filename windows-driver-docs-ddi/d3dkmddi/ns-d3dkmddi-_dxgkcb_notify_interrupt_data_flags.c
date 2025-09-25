typedef struct _DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS {
  union {
    struct {
      UINT ValidPhysicalAdapterMask : 1;
      UINT HsyncFlipCompletion : 1;
      UINT EvaluateLegacyMonitoredFences : 1;
#if ...
      UINT Reserved : 29;
#else
      UINT Reserved : 31;
#endif
    };
    UINT Value;
  };
} DXGKCB_NOTIFY_INTERRUPT_DATA_FLAGS;