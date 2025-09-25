LPFN_WSARECVMSG LpfnWsarecvmsg;

INT LpfnWsarecvmsg(
  SOCKET s,
  LPWSAMSG lpMsg,
  LPDWORD lpdwNumberOfBytesRecvd,
  LPWSAOVERLAPPED lpOverlapped,
  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
)
{...}