typedef union _RPC_ASYNC_NOTIFICATION_INFO {
  struct {
    PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
    HANDLE                      hThread;
  } APC;
  struct {
    HANDLE       hIOPort;
    DWORD        dwNumberOfBytesTransferred;
    DWORD_PTR    dwCompletionKey;
    LPOVERLAPPED lpOverlapped;
  } IOC;
  struct {
    HWND hWnd;
    UINT Msg;
  } HWND;
  HANDLE                      hEvent;
  PKEVENT                     Event;
  PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
} RPC_ASYNC_NOTIFICATION_INFO, *PRPC_ASYNC_NOTIFICATION_INFO;