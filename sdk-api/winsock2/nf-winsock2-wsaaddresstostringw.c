INT WSAAPI WSAAddressToStringW(
  [in]           LPSOCKADDR          lpsaAddress,
  [in]           DWORD               dwAddressLength,
  [in, optional] LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [in, out]      LPWSTR              lpszAddressString,
  [in, out]      LPDWORD             lpdwAddressStringLength
);