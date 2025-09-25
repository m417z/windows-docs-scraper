DWORD PXEAPI PxeDhcpGetVendorOptionValue(
  [in]            PVOID pPacket,
  [in]            ULONG uPacketLen,
  [in]            BYTE  bOption,
  [in]            ULONG uInstance,
  [out, optional] PBYTE pbOptionLen,
  [out, optional] PVOID *ppOptionValue
);