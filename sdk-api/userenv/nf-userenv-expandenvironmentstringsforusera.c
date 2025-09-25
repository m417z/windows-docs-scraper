USERENVAPI BOOL ExpandEnvironmentStringsForUserA(
  [in, optional] HANDLE hToken,
  [in]           LPCSTR lpSrc,
  [out]          LPSTR  lpDest,
  [in]           DWORD  dwSize
);