typedef struct _CLUSTER_HEALTH_FAULT {
  LPWSTR Id;
  DWORD  ErrorType;
  DWORD  ErrorCode;
  LPWSTR Description;
  LPWSTR Provider;
  DWORD  Flags;
  DWORD  Reserved;
} CLUSTER_HEALTH_FAULT, *PCLUSTER_HEALTH_FAULT;