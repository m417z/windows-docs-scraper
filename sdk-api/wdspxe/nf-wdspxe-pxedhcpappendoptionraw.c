DWORD PXEAPI PxeDhcpAppendOptionRaw(
  [in, out] PVOID  pReplyPacket,
  [in]      ULONG  uMaxReplyPacketLen,
  [in, out] PULONG puReplyPacketLen,
  [in]      USHORT uBufferLen,
  [in]      PVOID  pBuffer
);