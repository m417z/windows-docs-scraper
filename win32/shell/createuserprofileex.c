BOOL WINAPI CreateUserProfileEx(
  _In_      PSID    pSid,
  _In_      LPCTSTR lpUserName,
  _In_opt_  LPCTSTR lpUserHive,
  _Out_opt_ LPTSTR  lpProfileDir,
  _In_      DWORD   dwDirSize,
  _In_      BOOL    bWin9xUpg
);