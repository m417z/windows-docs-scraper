DWORD PXEAPI PxeDhcpv6GetOptionValue(
  [in]            PVOID pPacket,
  [in]            ULONG uPacketLen,
  [in]            ULONG uInstance,
  [in]            WORD  wOption,
  [out, optional] PWORD pwOptionLen,
  [out, optional] PVOID *ppOptionValue
);