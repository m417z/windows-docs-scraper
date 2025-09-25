typedef struct RESOURCE_STATUS {
  CLUSTER_RESOURCE_STATE ResourceState;
  DWORD                  CheckPoint;
  DWORD                  WaitHint;
  HANDLE                 EventHandle;
} RESOURCE_STATUS, *PRESOURCE_STATUS;