NTSTATUS NewStream(
  [out]          PMINIPORTWAVEPCISTREAM *Stream,
  [in, optional] PUNKNOWN               OuterUnknown,
  [in]           POOL_TYPE              PoolType,
  [in]           PPORTWAVEPCISTREAM     PortStream,
  [in]           ULONG                  Pin,
  [in]           BOOLEAN                Capture,
  [in]           PKSDATAFORMAT          DataFormat,
  [out]          PDMACHANNEL            *DmaChannel,
  [out]          PSERVICEGROUP          *ServiceGroup
);