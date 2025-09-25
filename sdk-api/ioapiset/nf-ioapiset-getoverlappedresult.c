BOOL GetOverlappedResult(
  [in]  HANDLE       hFile,
  [in]  LPOVERLAPPED lpOverlapped,
  [out] LPDWORD      lpNumberOfBytesTransferred,
  [in]  BOOL         bWait
);