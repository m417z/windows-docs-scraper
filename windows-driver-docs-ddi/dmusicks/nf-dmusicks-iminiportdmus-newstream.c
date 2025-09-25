NTSTATUS NewStream(
  [out]          PMXF             *MXF,
  [in, optional] PUNKNOWN         OuterUnknown,
  [in]           POOL_TYPE        PoolType,
  [in]           ULONG            PinID,
  [in]           DMUS_STREAM_TYPE StreamType,
  [in]           PKSDATAFORMAT    DataFormat,
  [out]          PSERVICEGROUP    *ServiceGroup,
  [in]           PAllocatorMXF    AllocatorMXF,
  [in]           PMASTERCLOCK     MasterClock,
  [out]          PULONGLONG       SchedulePreFetch
);