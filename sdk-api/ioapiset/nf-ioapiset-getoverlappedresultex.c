BOOL GetOverlappedResultEx(
  [in]  HANDLE       hFile,
  [in]  LPOVERLAPPED lpOverlapped,
  [out] LPDWORD      lpNumberOfBytesTransferred,
  [in]  DWORD        dwMilliseconds,
  [in]  BOOL         bAlertable
);