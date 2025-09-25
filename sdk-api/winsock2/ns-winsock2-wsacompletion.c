typedef struct _WSACOMPLETION {
  WSACOMPLETIONTYPE Type;
  union {
    struct {
      HWND   hWnd;
      UINT   uMsg;
      WPARAM context;
    } WindowMessage;
    struct {
      LPWSAOVERLAPPED lpOverlapped;
    } Event;
    struct {
      LPWSAOVERLAPPED                    lpOverlapped;
      LPWSAOVERLAPPED_COMPLETION_ROUTINE lpfnCompletionProc;
    } Apc;
    struct {
      LPWSAOVERLAPPED lpOverlapped;
      HANDLE          hPort;
      ULONG_PTR       Key;
    } Port;
  } Parameters;
} WSACOMPLETION, *PWSACOMPLETION, *LPWSACOMPLETION;