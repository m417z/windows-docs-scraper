HDDEDATA DdeClientTransaction(
  [in, optional]  LPBYTE  pData,
  [in]            DWORD   cbData,
  [in]            HCONV   hConv,
  [in, optional]  HSZ     hszItem,
  [in]            UINT    wFmt,
  [in]            UINT    wType,
  [in]            DWORD   dwTimeout,
  [out, optional] LPDWORD pdwResult
);