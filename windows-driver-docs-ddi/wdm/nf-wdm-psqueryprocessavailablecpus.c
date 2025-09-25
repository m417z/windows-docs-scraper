NTSTATUS PsQueryProcessAvailableCpus(
  [in]           PEPROCESS     Process,
  [in, out]      PKAFFINITY_EX Affinity,
  [in, optional] PULONG64      ObservedSequenceNumber,
  [out]          PULONG64      SequenceNumber
);