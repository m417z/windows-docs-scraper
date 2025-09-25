IPHLPAPI_DLL_LINKAGE DWORD GetOwnerModuleFromUdp6Entry(
  [in]      PMIB_UDP6ROW_OWNER_MODULE     pUdpEntry,
  [in]      TCPIP_OWNER_MODULE_INFO_CLASS Class,
  [out]     PVOID                         pBuffer,
  [in, out] PDWORD                        pdwSize
);