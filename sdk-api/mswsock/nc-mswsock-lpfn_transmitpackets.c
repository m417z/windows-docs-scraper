LPFN_TRANSMITPACKETS LpfnTransmitpackets;

BOOL LpfnTransmitpackets(
  SOCKET hSocket,
  LPTRANSMIT_PACKETS_ELEMENT lpPacketArray,
  DWORD nElementCount,
  DWORD nSendSize,
  LPOVERLAPPED lpOverlapped,
  DWORD dwFlags
)
{...}