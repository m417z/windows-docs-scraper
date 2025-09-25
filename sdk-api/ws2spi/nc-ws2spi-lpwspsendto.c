LPWSPSENDTO Lpwspsendto;

int Lpwspsendto(
  [in]  SOCKET s,
  [in]  LPWSABUF lpBuffers,
  [in]  DWORD dwBufferCount,
  [out] LPDWORD lpNumberOfBytesSent,
  [in]  DWORD dwFlags,
  [in]  const sockaddr *lpTo,
  [in]  int iTolen,
  [in]  LPWSAOVERLAPPED lpOverlapped,
  [in]  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
  [in]  LPWSATHREADID lpThreadId,
  [out] LPINT lpErrno
)
{...}