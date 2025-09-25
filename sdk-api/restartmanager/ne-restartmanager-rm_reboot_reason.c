typedef enum _RM_REBOOT_REASON {
  RmRebootReasonNone = 0x0,
  RmRebootReasonPermissionDenied = 0x1,
  RmRebootReasonSessionMismatch = 0x2,
  RmRebootReasonCriticalProcess = 0x4,
  RmRebootReasonCriticalService = 0x8,
  RmRebootReasonDetectedSelf
} RM_REBOOT_REASON;