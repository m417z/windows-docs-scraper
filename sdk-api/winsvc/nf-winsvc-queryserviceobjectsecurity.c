BOOL QueryServiceObjectSecurity(
  [in]            SC_HANDLE            hService,
  [in]            SECURITY_INFORMATION dwSecurityInformation,
  [out, optional] PSECURITY_DESCRIPTOR lpSecurityDescriptor,
  [in]            DWORD                cbBufSize,
  [out]           LPDWORD              pcbBytesNeeded
);