_BOOL GetMonitorRedGreenOrBlueGain(
  [in]  HANDLE       hMonitor,
  [in]  MC_GAIN_TYPE gtGainType,
  [out] LPDWORD      pdwMinimumGain,
  [out] LPDWORD      pdwCurrentGain,
  [out] LPDWORD      pdwMaximumGain
);