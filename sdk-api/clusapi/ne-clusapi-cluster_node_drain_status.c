typedef enum CLUSTER_NODE_DRAIN_STATUS {
  NodeDrainStatusNotInitiated = 0,
  NodeDrainStatusInProgress,
  NodeDrainStatusCompleted,
  NodeDrainStatusFailed,
  ClusterNodeDrainStatusCount
} ;