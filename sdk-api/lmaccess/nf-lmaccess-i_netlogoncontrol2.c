NET_API_STATUS NET_API_FUNCTION I_NetLogonControl2(
  [in, optional] LPCWSTR ServerName,
  [in]           DWORD   FunctionCode,
  [in]           DWORD   QueryLevel,
  [in]           LPBYTE  Data,
  [out]          LPBYTE  *Buffer
);