_BOOL GetMonitorRedGreenOrBlueDrive(
  [in]  HANDLE        hMonitor,
  [in]  MC_DRIVE_TYPE dtDriveType,
  [out] LPDWORD       pdwMinimumDrive,
  [out] LPDWORD       pdwCurrentDrive,
  [out] LPDWORD       pdwMaximumDrive
);