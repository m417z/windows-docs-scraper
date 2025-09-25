SOCKET WSAAPI WSAAccept(
  [in]      SOCKET          s,
  [out]     sockaddr        *addr,
  [in, out] LPINT           addrlen,
  [in]      LPCONDITIONPROC lpfnCondition,
  [in]      DWORD_PTR       dwCallbackData
);