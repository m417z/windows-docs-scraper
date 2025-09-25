LPDHCP_NEWPKT LpdhcpNewpkt;

DWORD LpdhcpNewpkt(
  [in, out] LPBYTE *Packet,
  [in, out] DWORD *PacketSize,
  [in]      DWORD IpAddress,
  [in]      LPVOID Reserved,
  [in, out] LPVOID *PktContext,
  [out]     LPBOOL ProcessIt
)
{...}