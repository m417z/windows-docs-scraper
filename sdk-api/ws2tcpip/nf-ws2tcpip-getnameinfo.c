INT WSAAPI getnameinfo(
  [in]  const SOCKADDR *pSockaddr,
  [in]  socklen_t      SockaddrLength,
  [out] PCHAR          pNodeBuffer,
  [in]  DWORD          NodeBufferSize,
  [out] PCHAR          pServiceBuffer,
  [in]  DWORD          ServiceBufferSize,
  [in]  INT            Flags
);