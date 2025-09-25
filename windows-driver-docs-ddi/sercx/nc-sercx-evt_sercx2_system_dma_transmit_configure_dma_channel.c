EVT_SERCX2_SYSTEM_DMA_TRANSMIT_CONFIGURE_DMA_CHANNEL EvtSercx2SystemDmaTransmitConfigureDmaChannel;

NTSTATUS EvtSercx2SystemDmaTransmitConfigureDmaChannel(
  [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit,
  [in] PMDL Mdl,
  [in] ULONG Offset,
  [in] ULONG Length
)
{...}