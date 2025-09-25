LONG SCardReconnect(
  [in]            SCARDHANDLE hCard,
  [in]            DWORD       dwShareMode,
  [in]            DWORD       dwPreferredProtocols,
  [in]            DWORD       dwInitialization,
  [out, optional] LPDWORD     pdwActiveProtocol
);