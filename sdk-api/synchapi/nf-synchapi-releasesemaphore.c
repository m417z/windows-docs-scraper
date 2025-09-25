BOOL ReleaseSemaphore(
  [in]            HANDLE hSemaphore,
  [in]            LONG   lReleaseCount,
  [out, optional] LPLONG lpPreviousCount
);