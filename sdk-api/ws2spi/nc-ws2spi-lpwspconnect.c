LPWSPCONNECT Lpwspconnect;

int Lpwspconnect(
  [in]  SOCKET s,
  [in]  const sockaddr *name,
  [in]  int namelen,
  [in]  LPWSABUF lpCallerData,
  [out] LPWSABUF lpCalleeData,
  [in]  LPQOS lpSQOS,
  [in]  LPQOS lpGQOS,
  [out] LPINT lpErrno
)
{...}