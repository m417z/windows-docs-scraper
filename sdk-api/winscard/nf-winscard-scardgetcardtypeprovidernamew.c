LONG SCardGetCardTypeProviderNameW(
  [in]      SCARDCONTEXT hContext,
  [in]      LPCWSTR      szCardName,
  [in]      DWORD        dwProviderId,
  [out]     WCHAR        *szProvider,
  [in, out] LPDWORD      pcchProvider
);