int WSAAPI WSARecv(
  [in]      SOCKET                             s,
  [in, out] LPWSABUF                           lpBuffers,
  [in]      DWORD                              dwBufferCount,
  [out]     LPDWORD                            lpNumberOfBytesRecvd,
  [in, out] LPDWORD                            lpFlags,
  [in]      LPWSAOVERLAPPED                    lpOverlapped,
  [in]      LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);