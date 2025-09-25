USERENVAPI BOOL GetUserProfileDirectoryA(
  [in]            HANDLE  hToken,
  [out, optional] LPSTR   lpProfileDir,
  [in, out]       LPDWORD lpcchSize
);