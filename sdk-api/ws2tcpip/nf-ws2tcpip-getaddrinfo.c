INT WSAAPI getaddrinfo(
  [in, optional] PCSTR           pNodeName,
  [in, optional] PCSTR           pServiceName,
  [in, optional] const ADDRINFOA *pHints,
  [out]          PADDRINFOA      *ppResult
);