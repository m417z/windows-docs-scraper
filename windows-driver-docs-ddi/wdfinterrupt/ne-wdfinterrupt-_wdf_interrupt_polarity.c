typedef enum _WDF_INTERRUPT_POLARITY {
  WdfInterruptPolarityUnknown = 0,
  WdfInterruptActiveHigh,
  WdfInterruptActiveLow
} WDF_INTERRUPT_POLARITY, *PWDF_INTERRUPT_POLARITY;