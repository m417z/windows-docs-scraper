LONG SCardStatusW(
  [in]                SCARDHANDLE hCard,
  [out]               LPWSTR      mszReaderNames,
  [in, out, optional] LPDWORD     pcchReaderLen,
  [out, optional]     LPDWORD     pdwState,
  [out, optional]     LPDWORD     pdwProtocol,
  [out]               LPBYTE      pbAtr,
  [in, out, optional] LPDWORD     pcbAtrLen
);