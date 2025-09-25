HNETINTERFACE OpenClusterNetInterfaceEx(
  [in]            HCLUSTER hCluster,
  [in, optional]  LPCWSTR  lpszInterfaceName,
  [in]            DWORD    dwDesiredAccess,
  [out, optional] DWORD    *lpdwGrantedAccess
);