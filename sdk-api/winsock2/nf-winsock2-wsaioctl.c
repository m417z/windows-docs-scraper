int WSAAPI WSAIoctl(
  [in]  SOCKET                             s,
  [in]  DWORD                              dwIoControlCode,
  [in]  LPVOID                             lpvInBuffer,
  [in]  DWORD                              cbInBuffer,
  [out] LPVOID                             lpvOutBuffer,
  [in]  DWORD                              cbOutBuffer,
  [out] LPDWORD                            lpcbBytesReturned,
  [in]  LPWSAOVERLAPPED                    lpOverlapped,
  [in]  LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine
);