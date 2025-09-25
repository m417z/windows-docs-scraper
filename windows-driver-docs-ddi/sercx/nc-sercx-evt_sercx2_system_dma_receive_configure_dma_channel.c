EVT_SERCX2_SYSTEM_DMA_RECEIVE_CONFIGURE_DMA_CHANNEL EvtSercx2SystemDmaReceiveConfigureDmaChannel;

NTSTATUS EvtSercx2SystemDmaReceiveConfigureDmaChannel(
  [in] SERCX2SYSTEMDMARECEIVE SystemDmaReceive,
  [in] PMDL Mdl,
  [in] ULONG Offset,
  [in] ULONG Length
)
{...}