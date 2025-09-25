typedef struct _CREATE_CLUSTER_CONFIG {
  DWORD                      dwVersion;
  PCWSTR                     lpszClusterName;
  DWORD                      cNodes;
  PCWSTR                     *ppszNodeNames;
  DWORD                      cIpEntries;
  PCLUSTER_IP_ENTRY          pIpEntries;
  BOOLEAN                    fEmptyCluster;
  CLUSTER_MGMT_POINT_TYPE    managementPointType;
  CLUSTER_MGMT_POINT_RESTYPE managementPointResType;
  PCWSTR                     pszUserName;
  PCWSTR                     pszPassword;
  PCWSTR                     pszDomain;
} CREATE_CLUSTER_CONFIG, *PCREATE_CLUSTER_CONFIG;