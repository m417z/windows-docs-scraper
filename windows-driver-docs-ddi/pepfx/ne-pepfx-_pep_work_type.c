typedef enum _PEP_WORK_TYPE {
  PepWorkRequestPowerControl,
  PepWorkCompleteIdleState,
  PepWorkCompletePerfState,
  PepWorkAcpiNotify,
  PepWorkAcpiEvaluateControlMethodComplete,
  PepWorkMax
} PEP_WORK_TYPE, *PPEP_WORK_TYPE;