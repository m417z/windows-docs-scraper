LPWSPRECV Lpwsprecv;

int Lpwsprecv(
  [in]         SOCKET s,
  \[in\, out\] LPWSABUF lpBuffers,
  [in]         DWORD dwBufferCount,
  [out]        LPDWORD lpNumberOfBytesRecvd,
  \[in\, out\] LPDWORD lpFlags,
  [in]         LPWSAOVERLAPPED lpOverlapped,
  [in]         LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine,
  [in]         LPWSATHREADID lpThreadId,
  [out]        LPINT lpErrno
)
{...}