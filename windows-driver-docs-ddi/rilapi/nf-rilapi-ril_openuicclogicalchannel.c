HRESULT RIL_OpenUiccLogicalChannel(
  HRIL       hRil,
  LPVOID     lpContext,
  DWORD      dwSlotIndex,
  DWORD      dwChannelGroup,
  DWORD      dwAppIdLength,
  const BYTE *pbAppId,
  DWORD      dwSelectP2Arg
);