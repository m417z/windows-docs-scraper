NTSTATUS KeConvertAuxiliaryCounterToPerformanceCounter(
  [in]            ULONG64  AuxiliaryCounterValue,
  [out]           PULONG64 PerformanceCounterValue,
  [out, optional] PULONG64 ConversionError
);