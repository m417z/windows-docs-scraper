typedef struct _CLUSTER_ENUM_ITEM {
  DWORD  dwVersion;
  DWORD  dwType;
  DWORD  cbId;
  LPWSTR lpszId;
  DWORD  cbName;
  LPWSTR lpszName;
} CLUSTER_ENUM_ITEM, *PCLUSTER_ENUM_ITEM;