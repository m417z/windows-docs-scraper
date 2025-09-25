typedef enum _CHANGER_DEVICE_PROBLEM_TYPE {
  DeviceProblemNone,
  DeviceProblemHardware,
  DeviceProblemCHMError,
  DeviceProblemDoorOpen,
  DeviceProblemCalibrationError,
  DeviceProblemTargetFailure,
  DeviceProblemCHMMoveError,
  DeviceProblemCHMZeroError,
  DeviceProblemCartridgeInsertError,
  DeviceProblemPositionError,
  DeviceProblemSensorError,
  DeviceProblemCartridgeEjectError,
  DeviceProblemGripperError,
  DeviceProblemDriveError
} CHANGER_DEVICE_PROBLEM_TYPE, *PCHANGER_DEVICE_PROBLEM_TYPE;