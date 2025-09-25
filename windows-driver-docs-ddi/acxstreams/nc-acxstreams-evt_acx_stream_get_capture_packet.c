EVT_ACX_STREAM_GET_CAPTURE_PACKET EvtAcxStreamGetCapturePacket;

NTSTATUS EvtAcxStreamGetCapturePacket(
  ACXSTREAM Stream,
  PULONG LastCapturePacket,
  PULONGLONG QPCPacketStart,
  PBOOLEAN MoreData
)
{...}