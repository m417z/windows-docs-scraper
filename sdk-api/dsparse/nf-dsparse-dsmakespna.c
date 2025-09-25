DSPARSE DWORD DsMakeSpnA(
  [in]           LPCSTR ServiceClass,
  [in]           LPCSTR ServiceName,
  [in, optional] LPCSTR InstanceName,
  [in]           USHORT InstancePort,
  [in, optional] LPCSTR Referrer,
  [in, out]      DWORD  *pcSpnLength,
  [out]          LPSTR  pszSpn
);