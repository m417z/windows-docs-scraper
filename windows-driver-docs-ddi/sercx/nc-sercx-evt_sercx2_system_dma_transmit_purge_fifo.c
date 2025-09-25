EVT_SERCX2_SYSTEM_DMA_TRANSMIT_PURGE_FIFO EvtSercx2SystemDmaTransmitPurgeFifo;

VOID EvtSercx2SystemDmaTransmitPurgeFifo(
  [in] SERCX2SYSTEMDMATRANSMIT SystemDmaTransmit,
  [in] ULONG BytesAlreadyTransmittedToHardware
)
{...}