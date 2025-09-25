typedef struct _CREATE_CLUSTER_NAME_ACCOUNT {
  DWORD                      dwVersion;
  PCWSTR                     lpszClusterName;
  DWORD                      dwFlags;
  PCWSTR                     pszUserName;
  PCWSTR                     pszPassword;
  PCWSTR                     pszDomain;
  CLUSTER_MGMT_POINT_TYPE    managementPointType;
  CLUSTER_MGMT_POINT_RESTYPE managementPointResType;
  BOOLEAN                    bUpgradeVCOs;
} CREATE_CLUSTER_NAME_ACCOUNT, *PCREATE_CLUSTER_NAME_ACCOUNT;