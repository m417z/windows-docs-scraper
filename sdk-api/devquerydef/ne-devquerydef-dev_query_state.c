typedef enum _DEV_QUERY_STATE {
  DevQueryStateInitialized,
  DevQueryStateEnumCompleted,
  DevQueryStateAborted,
  DevQueryStateClosed
} DEV_QUERY_STATE, *PDEV_QUERY_STATE;