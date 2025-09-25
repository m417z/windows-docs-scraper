LONG SCardListInterfacesW(
  [in]      SCARDCONTEXT hContext,
  [in]      LPCWSTR      szCard,
  [out]     LPGUID       pguidInterfaces,
  [in, out] LPDWORD      pcguidInterfaces
);