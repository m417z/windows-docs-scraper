typedef enum RESOURCE_MONITOR_STATE {
  RmonInitializing,
  RmonIdle,
  RmonStartingResource,
  RmonInitializingResource,
  RmonOnlineResource,
  RmonOfflineResource,
  RmonShutdownResource,
  RmonDeletingResource,
  RmonIsAlivePoll,
  RmonLooksAlivePoll,
  RmonArbitrateResource,
  RmonReleaseResource,
  RmonResourceControl,
  RmonResourceTypeControl,
  RmonTerminateResource,
  RmonDeadlocked
} ;