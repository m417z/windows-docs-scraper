LPWSPRECVDISCONNECT Lpwsprecvdisconnect;

int Lpwsprecvdisconnect(
  [in]  SOCKET s,
  [out] LPWSABUF lpInboundDisconnectData,
  [out] LPINT lpErrno
)
{...}