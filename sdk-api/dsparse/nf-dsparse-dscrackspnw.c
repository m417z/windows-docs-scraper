DSPARSE DWORD DsCrackSpnW(
  [in]                LPCWSTR pszSpn,
  [in, out, optional] DWORD   *pcServiceClass,
  [out, optional]     LPWSTR  ServiceClass,
  [in, out, optional] DWORD   *pcServiceName,
  [out, optional]     LPWSTR  ServiceName,
  [in, out, optional] DWORD   *pcInstanceName,
  [out, optional]     LPWSTR  InstanceName,
  [out, optional]     USHORT  *pInstancePort
);