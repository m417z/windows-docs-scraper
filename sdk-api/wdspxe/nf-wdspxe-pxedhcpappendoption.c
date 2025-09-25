DWORD PXEAPI PxeDhcpAppendOption(
  [in, out] PVOID  pReplyPacket,
  [in]      ULONG  uMaxReplyPacketLen,
  [in, out] PULONG puReplyPacketLen,
  [in]      BYTE   bOption,
  [in]      BYTE   bOptionLen,
  [in]      PVOID  pValue
);