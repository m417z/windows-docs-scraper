INT WSAAPI WSALookupServiceNextA(
  [in]      HANDLE         hLookup,
  [in]      DWORD          dwControlFlags,
  [in, out] LPDWORD        lpdwBufferLength,
  [out]     LPWSAQUERYSETA lpqsResults
);