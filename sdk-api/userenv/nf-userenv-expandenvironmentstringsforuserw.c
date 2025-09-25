USERENVAPI BOOL ExpandEnvironmentStringsForUserW(
  [in, optional] HANDLE  hToken,
  [in]           LPCWSTR lpSrc,
  [out]          LPWSTR  lpDest,
  [in]           DWORD   dwSize
);