INT WSAAPI WSAAddressToStringA(
  [in]           LPSOCKADDR          lpsaAddress,
  [in]           DWORD               dwAddressLength,
  [in, optional] LPWSAPROTOCOL_INFOA lpProtocolInfo,
  [in, out]      LPSTR               lpszAddressString,
  [in, out]      LPDWORD             lpdwAddressStringLength
);