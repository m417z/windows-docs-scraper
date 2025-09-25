BOOL ReadDirectoryChangesW(
  [in]                HANDLE                          hDirectory,
  [out]               LPVOID                          lpBuffer,
  [in]                DWORD                           nBufferLength,
  [in]                BOOL                            bWatchSubtree,
  [in]                DWORD                           dwNotifyFilter,
  [out, optional]     LPDWORD                         lpBytesReturned,
  [in, out, optional] LPOVERLAPPED                    lpOverlapped,
  [in, optional]      LPOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);