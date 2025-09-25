typedef enum _DXGK_CONNECTION_STATUS {
  ConnectionStatusUninitialized,
  TargetStatusDisconnected,
  TargetStatusConnected,
  TargetStatusJoined,
  MonitorStatusDisconnected,
  MonitorStatusUnknown,
  MonitorStatusConnected,
  LinkConfigurationStarted,
  LinkConfigurationFailed,
  LinkConfigurationSucceeded
} DXGK_CONNECTION_STATUS, *PDXGK_CONNECTION_STATUS;