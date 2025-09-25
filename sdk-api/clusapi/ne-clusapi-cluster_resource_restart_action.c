typedef enum CLUSTER_RESOURCE_RESTART_ACTION {
  ClusterResourceDontRestart = 0,
  ClusterResourceRestartNoNotify,
  ClusterResourceRestartNotify,
  ClusterResourceRestartActionCount
}  CRRA;