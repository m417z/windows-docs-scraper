typedef enum _MBB_WAKE_REASON_TYPE {
  MbbWakeReasonTypeRegisterState,
  MbbWakeReasonTypeSmsReceive,
  MbbWakeReasonTypeUssdReceive,
  MbbWakeReasonTypePacketState,
  MbbWakeReasonTypeUiccChange
} MBB_WAKE_REASON_TYPE;