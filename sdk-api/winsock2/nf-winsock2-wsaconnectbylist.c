BOOL WSAConnectByList(
  [in]      SOCKET               s,
  [in]      PSOCKET_ADDRESS_LIST SocketAddress,
  [in, out] LPDWORD              LocalAddressLength,
  [out]     LPSOCKADDR           LocalAddress,
  [in, out] LPDWORD              RemoteAddressLength,
  [out]     LPSOCKADDR           RemoteAddress,
  [in]      const timeval        *timeout,
  [in]      LPWSAOVERLAPPED      Reserved
);