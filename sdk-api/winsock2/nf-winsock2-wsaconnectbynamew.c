BOOL WSAConnectByNameW(
  [in]      SOCKET          s,
  [in]      LPWSTR          nodename,
  [in]      LPWSTR          servicename,
  [in, out] LPDWORD         LocalAddressLength,
  [out]     LPSOCKADDR      LocalAddress,
  [in, out] LPDWORD         RemoteAddressLength,
  [out]     LPSOCKADDR      RemoteAddress,
  [in]      const timeval   *timeout,
            LPWSAOVERLAPPED Reserved
);