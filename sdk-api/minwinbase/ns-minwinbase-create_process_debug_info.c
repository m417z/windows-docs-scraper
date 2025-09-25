typedef struct _CREATE_PROCESS_DEBUG_INFO {
  HANDLE                 hFile;
  HANDLE                 hProcess;
  HANDLE                 hThread;
  LPVOID                 lpBaseOfImage;
  DWORD                  dwDebugInfoFileOffset;
  DWORD                  nDebugInfoSize;
  LPVOID                 lpThreadLocalBase;
  LPTHREAD_START_ROUTINE lpStartAddress;
  LPVOID                 lpImageName;
  WORD                   fUnicode;
} CREATE_PROCESS_DEBUG_INFO, *LPCREATE_PROCESS_DEBUG_INFO;