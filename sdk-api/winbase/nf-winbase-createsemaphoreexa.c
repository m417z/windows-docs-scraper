HANDLE CreateSemaphoreExA(
  [in, optional] LPSECURITY_ATTRIBUTES lpSemaphoreAttributes,
  [in]           LONG                  lInitialCount,
  [in]           LONG                  lMaximumCount,
  [in, optional] LPCSTR                lpName,
                 DWORD                 dwFlags,
  [in]           DWORD                 dwDesiredAccess
);