EVT_SERCX2_PIO_TRANSMIT_WRITE_BUFFER EvtSercx2PioTransmitWriteBuffer;

ULONG EvtSercx2PioTransmitWriteBuffer(
  [in] SERCX2PIOTRANSMIT PioTransmit,
  [in] PUCHAR Buffer,
  [in] ULONG Length
)
{...}