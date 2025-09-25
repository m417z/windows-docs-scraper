USERENVAPI BOOL GetUserProfileDirectoryW(
  [in]            HANDLE  hToken,
  [out, optional] LPWSTR  lpProfileDir,
  [in, out]       LPDWORD lpcchSize
);