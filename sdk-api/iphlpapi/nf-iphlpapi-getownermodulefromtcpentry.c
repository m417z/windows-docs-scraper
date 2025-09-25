IPHLPAPI_DLL_LINKAGE DWORD GetOwnerModuleFromTcpEntry(
  [in]      PMIB_TCPROW_OWNER_MODULE      pTcpEntry,
  [in]      TCPIP_OWNER_MODULE_INFO_CLASS Class,
  [out]     PVOID                         pBuffer,
  [in, out] PDWORD                        pdwSize
);