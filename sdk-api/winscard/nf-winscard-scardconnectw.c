LONG SCardConnectW(
  [in]  SCARDCONTEXT  hContext,
  [in]  LPCWSTR       szReader,
  [in]  DWORD         dwShareMode,
  [in]  DWORD         dwPreferredProtocols,
  [out] LPSCARDHANDLE phCard,
  [out] LPDWORD       pdwActiveProtocol
);