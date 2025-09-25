typedef enum CLUSTER_RESOURCE_STATE_CHANGE_REASON {
  eResourceStateChangeReasonUnknown = 0,
  eResourceStateChangeReasonMove,
  eResourceStateChangeReasonFailover,
  eResourceStateChangeReasonFailedMove,
  eResourceStateChangeReasonShutdown,
  eResourceStateChangeReasonRundown
} ;