HANDLE WSAAPI WSAAsyncGetServByName(
  [in]  HWND       hWnd,
  [in]  u_int      wMsg,
  [in]  const char *name,
  [in]  const char *proto,
  [out] char       *buf,
  [in]  int        buflen
);