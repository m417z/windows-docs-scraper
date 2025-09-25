HANDLE OpenFileById(
  [in]           HANDLE                hVolumeHint,
  [in]           LPFILE_ID_DESCRIPTOR  lpFileId,
  [in]           DWORD                 dwDesiredAccess,
  [in]           DWORD                 dwShareMode,
  [in, optional] LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  [in]           DWORD                 dwFlagsAndAttributes
);