DWORD PXEAPI PxeDhcpInitialize(
  [in]      PVOID  pRecvPacket,
  [in]      ULONG  uRecvPacketLen,
  [in, out] PVOID  pReplyPacket,
  [in]      ULONG  uMaxReplyPacketLen,
  [out]     PULONG puReplyPacketLen
);