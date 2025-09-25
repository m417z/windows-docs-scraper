BOOL AcceptEx(
  [in]  SOCKET       sListenSocket,
  [in]  SOCKET       sAcceptSocket,
  [in]  PVOID        lpOutputBuffer,
  [in]  DWORD        dwReceiveDataLength,
  [in]  DWORD        dwLocalAddressLength,
  [in]  DWORD        dwRemoteAddressLength,
  [out] LPDWORD      lpdwBytesReceived,
  [in]  LPOVERLAPPED lpOverlapped
);