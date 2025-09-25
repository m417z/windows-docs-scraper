typedef enum _WDF_STATE_NOTIFICATION_TYPE {
  StateNotificationInvalid = 0x0000,
  StateNotificationEnterState = 0x0001,
  StateNotificationPostProcessState = 0x0002,
  StateNotificationLeaveState = 0x0004,
  StateNotificationAllStates = StateNotificationEnterState | StateNotificationPostProcessState | StateNotificationLeaveState
} WDF_STATE_NOTIFICATION_TYPE;