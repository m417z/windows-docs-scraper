BOOL ReadDirectoryChangesExW(
  [in]                HANDLE                                  hDirectory,
  [out]               LPVOID                                  lpBuffer,
  [in]                DWORD                                   nBufferLength,
  [in]                BOOL                                    bWatchSubtree,
  [in]                DWORD                                   dwNotifyFilter,
  [out, optional]     LPDWORD                                 lpBytesReturned,
  [in, out, optional] LPOVERLAPPED                            lpOverlapped,
  [in, optional]      LPOVERLAPPED_COMPLETION_ROUTINE         lpCompletionRoutine,
  [in]                READ_DIRECTORY_NOTIFY_INFORMATION_CLASS ReadDirectoryNotifyInformationClass
);