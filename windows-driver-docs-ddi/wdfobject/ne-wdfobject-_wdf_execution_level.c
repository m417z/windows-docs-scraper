typedef enum _WDF_EXECUTION_LEVEL {
  WdfExecutionLevelInvalid = 0x00,
  WdfExecutionLevelInheritFromParent,
  WdfExecutionLevelPassive,
  WdfExecutionLevelDispatch
} WDF_EXECUTION_LEVEL;