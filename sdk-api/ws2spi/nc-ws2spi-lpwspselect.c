LPWSPSELECT Lpwspselect;

int Lpwspselect(
  [in]      int nfds,
  [in, out] fd_set *readfds,
  [in, out] fd_set *writefds,
  [in, out] fd_set *exceptfds,
  [in]      const timeval *timeout,
  [out]     LPINT lpErrno
)
{...}