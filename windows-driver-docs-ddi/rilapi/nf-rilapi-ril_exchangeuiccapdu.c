HRESULT RIL_ExchangeUiccAPDU(
  HRIL       hRil,
  LPVOID     lpContext,
  DWORD      dwSlotIndex,
  DWORD      dwChannelId,
  DWORD      dwAPDULength,
  const BYTE *bAPDU
);