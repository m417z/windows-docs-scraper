WINSTORAGEAPI HANDLE CreateFile2FromAppW(
  LPCWSTR                           lpFileName,
  DWORD                             dwDesiredAccess,
  DWORD                             dwShareMode,
  DWORD                             dwCreationDisposition,
  LPCREATEFILE2_EXTENDED_PARAMETERS pCreateExParams
) noexcept;