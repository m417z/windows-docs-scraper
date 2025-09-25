BOOL LockFileEx(
  [in]      HANDLE       hFile,
  [in]      DWORD        dwFlags,
            DWORD        dwReserved,
  [in]      DWORD        nNumberOfBytesToLockLow,
  [in]      DWORD        nNumberOfBytesToLockHigh,
  [in, out] LPOVERLAPPED lpOverlapped
);