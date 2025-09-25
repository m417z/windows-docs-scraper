LONG SCardStatusA(
  [in]                SCARDHANDLE hCard,
  [out]               LPSTR       mszReaderNames,
  [in, out, optional] LPDWORD     pcchReaderLen,
  [out, optional]     LPDWORD     pdwState,
  [out, optional]     LPDWORD     pdwProtocol,
  [out]               LPBYTE      pbAtr,
  [in, out, optional] LPDWORD     pcbAtrLen
);