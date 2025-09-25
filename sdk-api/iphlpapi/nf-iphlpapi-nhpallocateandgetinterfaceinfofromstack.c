IPHLPAPI_DLL_LINKAGE DWORD NhpAllocateAndGetInterfaceInfoFromStack(
  IP_INTERFACE_NAME_INFO **ppTable,
  PDWORD                 pdwCount,
  BOOL                   bOrder,
  HANDLE                 hHeap,
  DWORD                  dwFlags
);