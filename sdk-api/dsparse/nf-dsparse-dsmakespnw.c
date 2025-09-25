DSPARSE DWORD DsMakeSpnW(
  [in]           LPCWSTR ServiceClass,
  [in]           LPCWSTR ServiceName,
  [in, optional] LPCWSTR InstanceName,
  [in]           USHORT  InstancePort,
  [in, optional] LPCWSTR Referrer,
  [in, out]      DWORD   *pcSpnLength,
  [out]          LPWSTR  pszSpn
);