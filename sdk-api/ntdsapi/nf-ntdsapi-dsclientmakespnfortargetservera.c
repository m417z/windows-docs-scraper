NTDSAPI DWORD DsClientMakeSpnForTargetServerA(
  [in]      LPCSTR ServiceClass,
  [in]      LPCSTR ServiceName,
  [in, out] DWORD  *pcSpnLength,
  [out]     LPSTR  pszSpn
);