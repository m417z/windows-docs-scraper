typedef struct _CLUS_PROVIDER_STATE_CHANGE_INFO {
  DWORD                  dwSize;
  CLUSTER_RESOURCE_STATE resourceState;
  WCHAR                  szProviderId[1];
} CLUS_PROVIDER_STATE_CHANGE_INFO, *PCLUS_PROVIDER_STATE_CHANGE_INFO;