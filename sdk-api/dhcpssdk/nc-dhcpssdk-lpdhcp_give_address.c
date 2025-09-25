LPDHCP_GIVE_ADDRESS LpdhcpGiveAddress;

DWORD LpdhcpGiveAddress(
  [in] LPBYTE Packet,
  [in] DWORD PacketSize,
  [in] DWORD ControlCode,
  [in] DWORD IpAddress,
  [in] DWORD AltAddress,
  [in] DWORD AddrType,
  [in] DWORD LeaseTime,
  [in] LPVOID Reserved,
  [in] LPVOID PktContext
)
{...}