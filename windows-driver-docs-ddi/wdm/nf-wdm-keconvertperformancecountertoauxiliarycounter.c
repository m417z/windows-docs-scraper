NTSTATUS KeConvertPerformanceCounterToAuxiliaryCounter(
  [in]            ULONG64  PerformanceCounterValue,
  [out]           PULONG64 AuxiliaryCounterValue,
  [out, optional] PULONG64 ConversionError
);