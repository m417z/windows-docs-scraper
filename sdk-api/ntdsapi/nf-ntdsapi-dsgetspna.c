NTDSAPI DWORD DsGetSpnA(
  [in]           DS_SPN_NAME_TYPE ServiceType,
  [in]           LPCSTR           ServiceClass,
  [in, optional] LPCSTR           ServiceName,
  [in]           USHORT           InstancePort,
  [in]           USHORT           cInstanceNames,
  [in, optional] LPCSTR           *pInstanceNames,
  [in, optional] const USHORT     *pInstancePorts,
  [out]          DWORD            *pcSpn,
  [out]          LPSTR            **prpszSpn
);