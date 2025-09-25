typedef enum _WDF_KPROCESSOR_MODE {
  WdfKProcessorModeInvalid,
  WdfKernelMode,
  WdfUserMode,
  WdfKProcessorModeMaximum
} WDF_KPROCESSOR_MODE, *PWDF_KPROCESSOR_MODE;