INT WSAAPI WSAStringToAddressA(
  [in]           LPSTR               AddressString,
  [in]           INT                 AddressFamily,
  [in, optional] LPWSAPROTOCOL_INFOA lpProtocolInfo,
  [out]          LPSOCKADDR          lpAddress,
  [in, out]      LPINT               lpAddressLength
);