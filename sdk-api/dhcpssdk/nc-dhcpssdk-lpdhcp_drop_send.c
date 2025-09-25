LPDHCP_DROP_SEND LpdhcpDropSend;

DWORD LpdhcpDropSend(
  [in, out] LPBYTE *Packet,
  [in, out] DWORD *PacketSize,
  [in]      DWORD ControlCode,
  [in]      DWORD IpAddress,
  [in]      LPVOID Reserved,
  [in]      LPVOID PktContext
)
{...}