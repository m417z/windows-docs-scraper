LONG SCardConnectA(
  [in]  SCARDCONTEXT  hContext,
  [in]  LPCSTR        szReader,
  [in]  DWORD         dwShareMode,
  [in]  DWORD         dwPreferredProtocols,
  [out] LPSCARDHANDLE phCard,
  [out] LPDWORD       pdwActiveProtocol
);