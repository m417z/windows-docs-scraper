HANDLE CreateFile2(
  [in]           LPCWSTR                           lpFileName,
  [in]           DWORD                             dwDesiredAccess,
  [in]           DWORD                             dwShareMode,
  [in]           DWORD                             dwCreationDisposition,
  [in, optional] LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
);