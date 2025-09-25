BOOL WSAConnectByNameA(
  [in]      SOCKET          s,
  [in]      LPCSTR          nodename,
  [in]      LPCSTR          servicename,
  [in, out] LPDWORD         LocalAddressLength,
  [out]     LPSOCKADDR      LocalAddress,
  [in, out] LPDWORD         RemoteAddressLength,
  [out]     LPSOCKADDR      RemoteAddress,
  [in]      const timeval   *timeout,
            LPWSAOVERLAPPED Reserved
);