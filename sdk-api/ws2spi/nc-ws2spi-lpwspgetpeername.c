LPWSPGETPEERNAME Lpwspgetpeername;

int Lpwspgetpeername(
  [in]      SOCKET s,
  [out]     sockaddr *name,
  [in, out] LPINT namelen,
  [out]     LPINT lpErrno
)
{...}