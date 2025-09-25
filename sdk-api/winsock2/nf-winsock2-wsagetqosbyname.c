BOOL WSAAPI WSAGetQOSByName(
  [in]      SOCKET   s,
  [in, out] LPWSABUF lpQOSName,
  [out]     LPQOS    lpQOS
);