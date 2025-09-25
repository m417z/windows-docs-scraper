INT WSAAPI GetNameInfoW(
  [in]  const SOCKADDR *pSockaddr,
  [in]  socklen_t      SockaddrLength,
  [out] PWCHAR         pNodeBuffer,
  [in]  DWORD          NodeBufferSize,
  [out] PWCHAR         pServiceBuffer,
  [in]  DWORD          ServiceBufferSize,
  [in]  INT            Flags
);