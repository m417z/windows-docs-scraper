typedef struct _CREATE_THREAD_DEBUG_INFO {
  HANDLE                 hThread;
  LPVOID                 lpThreadLocalBase;
  LPTHREAD_START_ROUTINE lpStartAddress;
} CREATE_THREAD_DEBUG_INFO, *LPCREATE_THREAD_DEBUG_INFO;