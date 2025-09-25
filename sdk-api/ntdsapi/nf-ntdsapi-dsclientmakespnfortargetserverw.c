NTDSAPI DWORD DsClientMakeSpnForTargetServerW(
  [in]      LPCWSTR ServiceClass,
  [in]      LPCWSTR ServiceName,
  [in, out] DWORD   *pcSpnLength,
  [out]     LPWSTR  pszSpn
);