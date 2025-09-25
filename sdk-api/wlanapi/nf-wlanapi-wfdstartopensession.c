DWORD WFDStartOpenSession(
  [in]           HANDLE                             hClientHandle,
  [in]           PDOT11_MAC_ADDRESS                 pDeviceAddress,
  [in, optional] PVOID                              pvContext,
  [in]           WFD_OPEN_SESSION_COMPLETE_CALLBACK pfnCallback,
  [out]          PHANDLE                            phSessionHandle
);