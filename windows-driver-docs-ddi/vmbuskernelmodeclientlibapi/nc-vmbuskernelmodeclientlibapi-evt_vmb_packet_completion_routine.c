EVT_VMB_PACKET_COMPLETION_ROUTINE EvtVmbPacketCompletionRoutine;

VOID EvtVmbPacketCompletionRoutine(
  [in] VMBPACKET Packet,
  [in] NTSTATUS Status,
  [in] PVOID Buffer,
  [in] UINT32 BufferLength
)
{...}