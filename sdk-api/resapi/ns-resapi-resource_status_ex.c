typedef struct RESOURCE_STATUS_EX {
  CLUSTER_RESOURCE_STATE ResourceState;
  DWORD                  CheckPoint;
  HANDLE                 EventHandle;
  DWORD                  ApplicationSpecificErrorCode;
  DWORD                  Flags;
  DWORD                  WaitHint;
} RESOURCE_STATUS_EX, *PRESOURCE_STATUS_EX;