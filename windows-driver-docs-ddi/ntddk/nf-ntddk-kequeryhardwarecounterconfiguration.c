NTSTATUS KeQueryHardwareCounterConfiguration(
  [out] PHARDWARE_COUNTER CounterArray,
  [in]  ULONG             MaximumCount,
  [out] PULONG            Count
);