int WSAAPI getsockopt(
  [in]      SOCKET s,
  [in]      int    level,
  [in]      int    optname,
  [out]     char   *optval,
  [in, out] int    *optlen
);