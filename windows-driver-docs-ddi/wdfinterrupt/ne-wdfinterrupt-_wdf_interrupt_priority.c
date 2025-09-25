typedef enum _WDF_INTERRUPT_PRIORITY {
  WdfIrqPriorityUndefined = 0,
  WdfIrqPriorityLow,
  WdfIrqPriorityNormal,
  WdfIrqPriorityHigh
} WDF_INTERRUPT_PRIORITY, *PWDF_INTERRUPT_PRIORITY;