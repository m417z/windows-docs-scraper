BOOL UnlockFileEx(
  [in]      HANDLE       hFile,
            DWORD        dwReserved,
  [in]      DWORD        nNumberOfBytesToUnlockLow,
  [in]      DWORD        nNumberOfBytesToUnlockHigh,
  [in, out] LPOVERLAPPED lpOverlapped
);