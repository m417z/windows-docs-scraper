void NdfCreateWinSockIncident(
                 SOCKET    sock,
  [in, optional] LPCWSTR   host,
                 USHORT    port,
  [in, optional] LPCWSTR   appId,
  [in, optional] SID       *userId,
  [out]          NDFHANDLE *handle
);