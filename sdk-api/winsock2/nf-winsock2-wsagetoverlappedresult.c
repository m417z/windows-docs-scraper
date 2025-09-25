BOOL WSAAPI WSAGetOverlappedResult(
  [in]  SOCKET          s,
  [in]  LPWSAOVERLAPPED lpOverlapped,
  [out] LPDWORD         lpcbTransfer,
  [in]  BOOL            fWait,
  [out] LPDWORD         lpdwFlags
);