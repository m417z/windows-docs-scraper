BOOL ReadFileEx(
  [in]            HANDLE                          hFile,
  [out, optional] LPVOID                          lpBuffer,
  [in]            DWORD                           nNumberOfBytesToRead,
  [in, out]       LPOVERLAPPED                    lpOverlapped,
  [in]            LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);