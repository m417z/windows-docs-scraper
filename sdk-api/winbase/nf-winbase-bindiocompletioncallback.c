BOOL BindIoCompletionCallback(
  [in] HANDLE                          FileHandle,
  [in] LPOVERLAPPED_COMPLETION_ROUTINE Function,
  [in] ULONG                           Flags
);