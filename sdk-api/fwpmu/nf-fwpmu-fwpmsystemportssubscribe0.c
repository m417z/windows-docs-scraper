DWORD FwpmSystemPortsSubscribe0(
  [in, optional] HANDLE                      engineHandle,
                 void                        *reserved,
  [in]           FWPM_SYSTEM_PORTS_CALLBACK0 callback,
  [in, optional] void                        *context,
  [out]          HANDLE                      *sysPortsHandle
);