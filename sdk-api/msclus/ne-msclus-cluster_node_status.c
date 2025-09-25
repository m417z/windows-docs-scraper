typedef enum CLUSTER_NODE_STATUS {
  NodeStatusNormal = 0,
  NodeStatusIsolated = 0x1,
  NodeStatusQuarantined = 0x2,
  NodeStatusDrainInProgress = 0x4,
  NodeStatusDrainCompleted = 0x8,
  NodeStatusDrainFailed = 0x10,
  NodeStatusAvoidPlacement = 0x20,
  NodeStatusMax
} ;