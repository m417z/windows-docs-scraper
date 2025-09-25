typedef enum _RM_APP_STATUS {
  RmStatusUnknown = 0x0,
  RmStatusRunning = 0x1,
  RmStatusStopped = 0x2,
  RmStatusStoppedOther = 0x4,
  RmStatusRestarted = 0x8,
  RmStatusErrorOnStop = 0x10,
  RmStatusErrorOnRestart = 0x20,
  RmStatusShutdownMasked = 0x40,
  RmStatusRestartMasked = 0x80
} RM_APP_STATUS;