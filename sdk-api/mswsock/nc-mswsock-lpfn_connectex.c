LPFN_CONNECTEX LpfnConnectex;

BOOL LpfnConnectex(
  [in]           SOCKET s,
  [in]           const sockaddr *name,
  [in]           int namelen,
  [in, optional] PVOID lpSendBuffer,
  [in]           DWORD dwSendDataLength,
  [out]          LPDWORD lpdwBytesSent,
  [in]           LPOVERLAPPED lpOverlapped
)
{...}