typedef struct _WDF_TIMER_CONFIG {
  ULONG         Size;
  PFN_WDF_TIMER EvtTimerFunc;
  ULONG         Period;
  BOOLEAN       AutomaticSerialization;
  ULONG         TolerableDelay;
  BOOLEAN       UseHighResolutionTimer;
} WDF_TIMER_CONFIG, *PWDF_TIMER_CONFIG;