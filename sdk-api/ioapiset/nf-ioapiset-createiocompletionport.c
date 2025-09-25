HANDLE CreateIoCompletionPort(
  [in]           HANDLE    FileHandle,
  [in, optional] HANDLE    ExistingCompletionPort,
  [in]           ULONG_PTR CompletionKey,
  [in]           DWORD     NumberOfConcurrentThreads
);