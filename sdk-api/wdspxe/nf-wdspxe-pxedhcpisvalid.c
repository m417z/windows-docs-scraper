DWORD PXEAPI PxeDhcpIsValid(
  [in]  PVOID pPacket,
  [in]  ULONG uPacketLen,
  [in]  BOOL  bRequestPacket,
  [out] PBOOL pbPxeOptionPresent
);