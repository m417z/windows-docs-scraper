HANDLE WSAAPI WSAAsyncGetProtoByName(
  [in]  HWND       hWnd,
  [in]  u_int      wMsg,
  [in]  const char *name,
  [out] char       *buf,
  [out] int        buflen
);