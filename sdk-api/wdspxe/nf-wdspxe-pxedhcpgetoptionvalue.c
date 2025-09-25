DWORD PXEAPI PxeDhcpGetOptionValue(
  [in]            PVOID pPacket,
  [in]            ULONG uPacketLen,
  [in]            ULONG uInstance,
  [in]            BYTE  bOption,
  [out, optional] PBYTE pbOptionLen,
  [out, optional] PVOID *ppOptionValue
);