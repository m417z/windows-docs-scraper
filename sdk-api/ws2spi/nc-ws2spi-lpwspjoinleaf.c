LPWSPJOINLEAF Lpwspjoinleaf;

SOCKET Lpwspjoinleaf(
  [in]  SOCKET s,
  [in]  const sockaddr *name,
  [in]  int namelen,
  [in]  LPWSABUF lpCallerData,
  [out] LPWSABUF lpCalleeData,
  [in]  LPQOS lpSQOS,
  [in]  LPQOS lpGQOS,
  [in]  DWORD dwFlags,
  [out] LPINT lpErrno
)
{...}