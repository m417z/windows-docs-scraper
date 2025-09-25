LONG SCardListInterfacesA(
  [in]      SCARDCONTEXT hContext,
  [in]      LPCSTR       szCard,
  [out]     LPGUID       pguidInterfaces,
  [in, out] LPDWORD      pcguidInterfaces
);