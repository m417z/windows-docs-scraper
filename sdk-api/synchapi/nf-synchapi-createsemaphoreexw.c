HANDLE CreateSemaphoreExW(
  [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
  [in]           LONG                  lInitialCount,
  [in]           LONG                  lMaximumCount,
  [in, optional] LPCWSTR               lpName,
                 DWORD                 dwFlags,
  [in]           DWORD                 dwDesiredAccess
);