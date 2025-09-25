EVT_SERCX2_PIO_RECEIVE_READ_BUFFER EvtSercx2PioReceiveReadBuffer;

ULONG EvtSercx2PioReceiveReadBuffer(
  [in]  SERCX2PIORECEIVE PioReceive,
  [out] PUCHAR Buffer,
  [in]  ULONG Length
)
{...}