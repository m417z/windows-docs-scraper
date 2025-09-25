HANDLE CreateMutexExW(
  [in, optional] LPSECURITY_ATTRIBUTES lpMutexAttributes,
  [in, optional] LPCWSTR               lpName,
  [in]           DWORD                 dwFlags,
  [in]           DWORD                 dwDesiredAccess
);