LPWSPRECVFROM Lpwsprecvfrom;

int Lpwsprecvfrom(
  [in]      SOCKET s,
  [in, out] LPWSABUF lpBuffers,
  [in]      DWORD dwBufferCount,
  [out]     LPDWORD lpNumberOfBytesRecvd,
  [in, out] LPDWORD lpFlags,
  [out]     sockaddr *lpFrom,
  [in, out] LPINT lpFromlen,
  [in]      LPWSAOVERLAPPED lpOverlapped,
  [in]      LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
  \[in\]    LPWSATHREADID lpThreadId,
  [in, out] LPINT lpErrno
)
{...}