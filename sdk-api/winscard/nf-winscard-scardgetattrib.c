LONG SCardGetAttrib(
  [in]      SCARDHANDLE hCard,
  [in]      DWORD       dwAttrId,
  [out]     LPBYTE      pbAttr,
  [in, out] LPDWORD     pcbAttrLen
);