NTDSAPI DWORD DsGetSpnW(
  [in]           DS_SPN_NAME_TYPE ServiceType,
  [in]           LPCWSTR          ServiceClass,
  [in, optional] LPCWSTR          ServiceName,
  [in]           USHORT           InstancePort,
  [in]           USHORT           cInstanceNames,
  [in, optional] LPCWSTR          *pInstanceNames,
  [in, optional] const USHORT     *pInstancePorts,
  [out]          DWORD            *pcSpn,
  [out]          LPWSTR           **prpszSpn
);