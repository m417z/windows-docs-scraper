NTSYSAPI NTSTATUS RtlInitializeCorrelationVector(
  [in, out] PCORRELATION_VECTOR CorrelationVector,
  [in]      int                 Version,
  [in]      const GUID          *Guid
);