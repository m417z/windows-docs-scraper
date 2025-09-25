typedef enum _TAPE_DRIVE_PROBLEM_TYPE {
  TapeDriveProblemNone,
  TapeDriveReadWriteWarning,
  TapeDriveReadWriteError,
  TapeDriveReadWarning,
  TapeDriveWriteWarning,
  TapeDriveReadError,
  TapeDriveWriteError,
  TapeDriveHardwareError,
  TapeDriveUnsupportedMedia,
  TapeDriveScsiConnectionError,
  TapeDriveTimetoClean,
  TapeDriveCleanDriveNow,
  TapeDriveMediaLifeExpired,
  TapeDriveSnappedTape
} TAPE_DRIVE_PROBLEM_TYPE;