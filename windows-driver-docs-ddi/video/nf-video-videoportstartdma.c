VIDEOPORT_DEPRECATED VIDEOPORT_API VP_STATUS VideoPortStartDma(
  [in]      IN PVOID           HwDeviceExtension,
  [in]      IN PVP_DMA_ADAPTER VpDmaAdapter,
  [in]      IN PVOID           Mdl,
  [in]      IN ULONG           Offset,
  [in, out] IN OUT PULONG      pLength,
  [in]      IN PEXECUTE_DMA    ExecuteDmaRoutine,
  [in]      IN PVOID           Context,
  [in]      IN BOOLEAN         WriteToDevice
);