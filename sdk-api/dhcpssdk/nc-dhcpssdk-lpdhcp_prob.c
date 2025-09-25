LPDHCP_PROB LpdhcpProb;

DWORD LpdhcpProb(
  [in] LPBYTE Packet,
  [in] DWORD PacketSize,
  [in] DWORD ControlCode,
  [in] DWORD IpAddress,
  [in] DWORD AltAddress,
  [in] LPVOID Reserved,
  [in] LPVOID PktContext
)
{...}