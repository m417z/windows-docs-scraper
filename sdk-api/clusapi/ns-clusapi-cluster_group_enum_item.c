typedef struct _CLUSTER_GROUP_ENUM_ITEM {
  DWORD               dwVersion;
  DWORD               cbId;
  LPWSTR              lpszId;
  DWORD               cbName;
  LPWSTR              lpszName;
  CLUSTER_GROUP_STATE state;
  DWORD               cbOwnerNode;
  LPWSTR              lpszOwnerNode;
  DWORD               dwFlags;
  DWORD               cbProperties;
  PVOID               pProperties;
  DWORD               cbRoProperties;
  PVOID               pRoProperties;
} CLUSTER_GROUP_ENUM_ITEM, *PCLUSTER_GROUP_ENUM_ITEM;