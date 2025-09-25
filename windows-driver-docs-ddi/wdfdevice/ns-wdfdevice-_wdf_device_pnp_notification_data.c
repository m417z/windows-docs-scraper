typedef struct _WDF_DEVICE_PNP_NOTIFICATION_DATA {
  WDF_STATE_NOTIFICATION_TYPE Type;
  union {
    struct {
      WDF_DEVICE_PNP_STATE CurrentState;
      WDF_DEVICE_PNP_STATE NewState;
    } EnterState;
    struct {
      WDF_DEVICE_PNP_STATE CurrentState;
    } PostProcessState;
    struct {
      WDF_DEVICE_PNP_STATE CurrentState;
      WDF_DEVICE_PNP_STATE NewState;
    } LeaveState;
  } Data;
} WDF_DEVICE_PNP_NOTIFICATION_DATA;