typedef enum CLUSTER_RESOURCE_STATE {
  ClusterResourceStateUnknown = -1,
  ClusterResourceInherited,
  ClusterResourceInitializing,
  ClusterResourceOnline,
  ClusterResourceOffline,
  ClusterResourceFailed,
  ClusterResourcePending = 128,
  ClusterResourceOnlinePending,
  ClusterResourceOfflinePending
} ;