BOOL WriteFileEx(
  [in]           HANDLE                          hFile,
  [in, optional] LPCVOID                         lpBuffer,
  [in]           DWORD                           nNumberOfBytesToWrite,
  [in, out]      LPOVERLAPPED                    lpOverlapped,
  [in]           LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);