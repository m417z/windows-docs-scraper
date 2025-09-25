LPWSPGETOVERLAPPEDRESULT Lpwspgetoverlappedresult;

BOOL Lpwspgetoverlappedresult(
  [in]  SOCKET s,
  [in]  LPWSAOVERLAPPED lpOverlapped,
  [out] LPDWORD lpcbTransfer,
  [in]  BOOL fWait,
  [out] LPDWORD lpdwFlags,
  [out] LPINT lpErrno
)
{...}