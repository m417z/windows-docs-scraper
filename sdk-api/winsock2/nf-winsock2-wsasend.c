int WSAAPI WSASend(
  [in]  SOCKET                             s,
  [in]  LPWSABUF                           lpBuffers,
  [in]  DWORD                              dwBufferCount,
  [out] LPDWORD                            lpNumberOfBytesSent,
  [in]  DWORD                              dwFlags,
  [in]  LPWSAOVERLAPPED                    lpOverlapped,
  [in]  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);