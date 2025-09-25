PORTCLASSAPI NTSTATUS PcNewDmaChannel(
  [out]          PDMACHANNEL         *OutDmaChannel,
  [in, optional] PUNKNOWN            OuterUnknown,
  [in]           POOL_TYPE           PoolType,
  [in]           PDEVICE_DESCRIPTION DeviceDescription,
  [in]           PDEVICE_OBJECT      DeviceObject
);