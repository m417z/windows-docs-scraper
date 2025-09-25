LPWSPGETQOSBYNAME Lpwspgetqosbyname;

BOOL Lpwspgetqosbyname(
  [in]      SOCKET s,
  [in, out] LPWSABUF lpQOSName,
  [out]     LPQOS lpQOS,
  [out]     LPINT lpErrno
)
{...}