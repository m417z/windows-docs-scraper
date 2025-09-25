LPWSPEVENTSELECT Lpwspeventselect;

int Lpwspeventselect(
  [in]  SOCKET s,
  [in]  WSAEVENT hEventObject,
  [in]  long lNetworkEvents,
  [out] LPINT lpErrno
)
{...}