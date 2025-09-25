IPHLPAPI_DLL_LINKAGE DWORD GetOwnerModuleFromUdpEntry(
  [in]      PMIB_UDPROW_OWNER_MODULE      pUdpEntry,
  [in]      TCPIP_OWNER_MODULE_INFO_CLASS Class,
  [out]     PVOID                         pBuffer,
  [in, out] PDWORD                        pdwSize
);