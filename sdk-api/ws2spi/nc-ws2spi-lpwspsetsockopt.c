LPWSPSETSOCKOPT Lpwspsetsockopt;

int Lpwspsetsockopt(
  [in]  SOCKET s,
  [in]  int level,
  [in]  int optname,
  [in]  const char *optval,
  [in]  int optlen,
  [out] LPINT lpErrno
)
{...}