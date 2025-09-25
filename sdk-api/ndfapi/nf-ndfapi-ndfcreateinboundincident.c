void NdfCreateInboundIncident(
  [in, optional] LPCWSTR                applicationID,
  [in, optional] LPCWSTR                serviceID,
  [in, optional] SID                    *userID,
  [in, optional] const SOCKADDR_STORAGE *localTarget,
                 IPPROTO                protocol,
                 DWORD                  dwFlags,
  [out]          NDFHANDLE              *handle
);