HRESULT GetInterfaceContextTableForHostName(
  [in, optional] PCWSTR                      HostName,
  [in, optional] PCWSTR                      ProxyName,
  [in]           DWORD                       Flags,
  [in, optional] BYTE                        *ConnectionProfileFilterRawData,
  [in]           DWORD                       ConnectionProfileFilterRawDataSize,
  [out]          NET_INTERFACE_CONTEXT_TABLE **InterfaceContextTable
);