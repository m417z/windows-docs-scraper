NTSTATUS NewStream(
  [out]          PMINIPORTMIDISTREAM *Stream,
  [in, optional] PUNKNOWN            OuterUnknown,
  [in]           POOL_TYPE           PoolType,
  [in]           ULONG               Pin,
  [in]           BOOLEAN             Capture,
  [in]           PKSDATAFORMAT       DataFormat,
  [out]          PSERVICEGROUP       *ServiceGroup
);