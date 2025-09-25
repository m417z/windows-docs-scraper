NTSTATUS NewStream(
  [out]          PMINIPORTWAVECYCLICSTREAM *Stream,
  [in, optional] PUNKNOWN                  OuterUnknown,
  [in]           POOL_TYPE                 PoolType,
  [in]           ULONG                     Pin,
  [in]           BOOLEAN                   Capture,
  [in]           PKSDATAFORMAT             DataFormat,
  [out]          PDMACHANNEL               *DmaChannel,
  [out]          PSERVICEGROUP             *ServiceGroup
);