DWORD WDSBPAPI WdsBpParseInitializev6(
  [in]            PVOID  pPacket,
  [in]            ULONG  uPacketLen,
  [out, optional] PBYTE  pbPacketType,
  [out]           HANDLE *phHandle
);