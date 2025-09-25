LONG SCardGetCardTypeProviderNameA(
  [in]      SCARDCONTEXT hContext,
  [in]      LPCSTR       szCardName,
  [in]      DWORD        dwProviderId,
  [out]     CHAR         *szProvider,
  [in, out] LPDWORD      pcchProvider
);