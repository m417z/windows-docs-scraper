typedef struct _OVERLAPPED_ENTRY {
  ULONG_PTR    lpCompletionKey;
  LPOVERLAPPED lpOverlapped;
  ULONG_PTR    Internal;
  DWORD        dwNumberOfBytesTransferred;
} OVERLAPPED_ENTRY, *LPOVERLAPPED_ENTRY;