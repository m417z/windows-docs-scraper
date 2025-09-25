typedef struct lineinitializeexparams_tag {
  DWORD dwTotalSize;
  DWORD dwNeededSize;
  DWORD dwUsedSize;
  DWORD dwOptions;
  union {
    HANDLE hEvent;
    HANDLE hCompletionPort;
  } Handles;
  DWORD dwCompletionKey;
} LINEINITIALIZEEXPARAMS, *LPLINEINITIALIZEEXPARAMS;