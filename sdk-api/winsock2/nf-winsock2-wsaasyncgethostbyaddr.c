HANDLE WSAAPI WSAAsyncGetHostByAddr(
  HWND       hWnd,
  u_int      wMsg,
  const char *addr,
  int        len,
  int        type,
  char       *buf,
  int        buflen
);