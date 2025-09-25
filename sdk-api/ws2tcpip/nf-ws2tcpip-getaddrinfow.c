INT WSAAPI GetAddrInfoW(
  [in, optional] PCWSTR          pNodeName,
  [in, optional] PCWSTR          pServiceName,
  [in, optional] const ADDRINFOW *pHints,
  [out]          PADDRINFOW      *ppResult
);