LPFN_DISCONNECTEX LpfnDisconnectex;

BOOL LpfnDisconnectex(
  SOCKET s,
  LPOVERLAPPED lpOverlapped,
  DWORD dwFlags,
  DWORD dwReserved
)
{...}