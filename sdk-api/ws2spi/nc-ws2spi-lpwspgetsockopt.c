LPWSPGETSOCKOPT Lpwspgetsockopt;

int Lpwspgetsockopt(
  SOCKET s,
  int level,
  int optname,
  char *optval,
  LPINT optlen,
  LPINT lpErrno
)
{...}