int WSAAPI WSASendMsg(
  [in]  SOCKET                             Handle,
  [in]  LPWSAMSG                           lpMsg,
  [in]  DWORD                              dwFlags,
  [out] LPDWORD                            lpNumberOfBytesSent,
  [in]  LPWSAOVERLAPPED                    lpOverlapped,
  [in]  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);