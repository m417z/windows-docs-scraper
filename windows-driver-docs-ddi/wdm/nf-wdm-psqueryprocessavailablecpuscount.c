NTSTATUS PsQueryProcessAvailableCpusCount(
  [in]  PEPROCESS Process,
  [out] PULONG    AvailableCpuCount,
  [out] PULONG64  SequenceNumber
);