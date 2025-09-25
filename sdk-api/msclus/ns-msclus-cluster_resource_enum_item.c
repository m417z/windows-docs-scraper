typedef struct _CLUSTER_RESOURCE_ENUM_ITEM {
  DWORD  dwVersion;
  DWORD  cbId;
  LPWSTR lpszId;
  DWORD  cbName;
  LPWSTR lpszName;
  DWORD  cbOwnerGroupName;
  LPWSTR lpszOwnerGroupName;
  DWORD  cbOwnerGroupId;
  LPWSTR lpszOwnerGroupId;
  DWORD  cbProperties;
  PVOID  pProperties;
  DWORD  cbRoProperties;
  PVOID  pRoProperties;
} CLUSTER_RESOURCE_ENUM_ITEM, *PCLUSTER_RESOURCE_ENUM_ITEM;