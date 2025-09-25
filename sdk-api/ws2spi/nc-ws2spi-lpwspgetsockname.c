LPWSPGETSOCKNAME Lpwspgetsockname;

int Lpwspgetsockname(
  [in]      SOCKET s,
  [out]     sockaddr *name,
  [in, out] LPINT namelen,
  [out]     LPINT lpErrno
)
{...}