DSPARSE DWORD DsCrackSpnA(
  [in]                LPCSTR  pszSpn,
  [in, out, optional] LPDWORD pcServiceClass,
  [out, optional]     LPSTR   ServiceClass,
  [in, out, optional] LPDWORD pcServiceName,
  [out, optional]     LPSTR   ServiceName,
  [in, out, optional] LPDWORD pcInstanceName,
  [out, optional]     LPSTR   InstanceName,
  [out, optional]     USHORT  *pInstancePort
);