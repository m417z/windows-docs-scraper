typedef enum CLUSTER_NETWORK_STATE {
  ClusterNetworkStateUnknown = -1,
  ClusterNetworkUnavailable,
  ClusterNetworkDown,
  ClusterNetworkPartitioned,
  ClusterNetworkUp
} ;