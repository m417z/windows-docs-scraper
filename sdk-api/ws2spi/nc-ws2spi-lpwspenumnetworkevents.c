LPWSPENUMNETWORKEVENTS Lpwspenumnetworkevents;

int Lpwspenumnetworkevents(
  [in]  SOCKET s,
  [in]  WSAEVENT hEventObject,
  [out] LPWSANETWORKEVENTS lpNetworkEvents,
  [out] LPINT lpErrno
)
{...}