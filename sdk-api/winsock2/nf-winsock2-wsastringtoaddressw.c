INT WSAAPI WSAStringToAddressW(
  [in]           LPWSTR              AddressString,
  [in]           INT                 AddressFamily,
  [in, optional] LPWSAPROTOCOL_INFOW lpProtocolInfo,
  [out]          LPSOCKADDR          lpAddress,
  [in, out]      LPINT               lpAddressLength
);