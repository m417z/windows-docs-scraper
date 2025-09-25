typedef enum CLUSTER_GROUP_STATE {
  ClusterGroupStateUnknown = -1,
  ClusterGroupOnline = 206,
  ClusterGroupOffline,
  ClusterGroupFailed,
  ClusterGroupPartialOnline,
  ClusterGroupPending
} ;