HANDLE WSAAsyncGetServByPort(
  [in]  HWND       hWnd,
  [in]  u_int      wMsg,
  [in]  int        port,
  [in]  const char *proto,
  [out] char       *buf,
  [in]  int        buflen
);