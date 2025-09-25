LPWSPSENDDISCONNECT Lpwspsenddisconnect;

int Lpwspsenddisconnect(
  [in]  SOCKET s,
  [in]  LPWSABUF lpOutboundDisconnectData,
  [out] LPINT lpErrno
)
{...}