typedef enum CLUSTER_GROUP_STATE {
  ClusterGroupStateUnknown = -1,
  ClusterGroupOnline,
  ClusterGroupOffline,
  ClusterGroupFailed,
  ClusterGroupPartialOnline,
  ClusterGroupPending
} ;