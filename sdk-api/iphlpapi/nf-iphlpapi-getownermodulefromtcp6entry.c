IPHLPAPI_DLL_LINKAGE DWORD GetOwnerModuleFromTcp6Entry(
  [in]      PMIB_TCP6ROW_OWNER_MODULE     pTcpEntry,
  [in]      TCPIP_OWNER_MODULE_INFO_CLASS Class,
  [out]     PVOID                         pBuffer,
  [in, out] PDWORD                        pdwSize
);