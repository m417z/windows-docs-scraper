LONG SCardGetReaderIconW(
  [in]      SCARDCONTEXT hContext,
  [in]      LPCWSTR      szReaderName,
  [out]     LPBYTE       pbIcon,
  [in, out] LPDWORD      pcbIcon
);