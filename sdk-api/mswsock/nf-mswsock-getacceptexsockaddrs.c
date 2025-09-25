VOID GetAcceptExSockaddrs(
  [in]  PVOID    lpOutputBuffer,
  [in]  DWORD    dwReceiveDataLength,
  [in]  DWORD    dwLocalAddressLength,
  [in]  DWORD    dwRemoteAddressLength,
  [out] sockaddr **LocalSockaddr,
  [out] LPINT    LocalSockaddrLength,
  [out] sockaddr **RemoteSockaddr,
  [out] LPINT    RemoteSockaddrLength
);