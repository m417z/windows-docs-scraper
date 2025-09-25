DOT11EXT_SEND_PACKET Dot11extSendPacket;

DWORD Dot11extSendPacket(
  [in, optional] HANDLE hDot11SvcHandle,
  [in]           ULONG uPacketLen,
  [in]           LPVOID pvPacket,
  [in, optional] HANDLE hSendCompletion
)
{...}