typedef enum CLUSTER_RESOURCE_STATE_CHANGE_REASON {
  eResourceStateChangeReasonUnknown,
  eResourceStateChangeReasonMove,
  eResourceStateChangeReasonFailover,
  eResourceStateChangeReasonFailedMove,
  eResourceStateChangeReasonShutdown,
  eResourceStateChangeReasonRundown
} ;