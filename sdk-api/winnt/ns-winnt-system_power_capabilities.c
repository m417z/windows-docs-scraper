typedef struct {
  BOOLEAN                 PowerButtonPresent;
  BOOLEAN                 SleepButtonPresent;
  BOOLEAN                 LidPresent;
  BOOLEAN                 SystemS1;
  BOOLEAN                 SystemS2;
  BOOLEAN                 SystemS3;
  BOOLEAN                 SystemS4;
  BOOLEAN                 SystemS5;
  BOOLEAN                 HiberFilePresent;
  BOOLEAN                 FullWake;
  BOOLEAN                 VideoDimPresent;
  BOOLEAN                 ApmPresent;
  BOOLEAN                 UpsPresent;
  BOOLEAN                 ThermalControl;
  BOOLEAN                 ProcessorThrottle;
  BYTE                    ProcessorMinThrottle;
  BYTE                    ProcessorThrottleScale;
  BYTE                    spare2[4];
  BYTE                    ProcessorMaxThrottle;
  BOOLEAN                 FastSystemS4;
  BOOLEAN                 Hiberboot;
  BOOLEAN                 WakeAlarmPresent;
  BOOLEAN                 AoAc;
  BOOLEAN                 DiskSpinDown;
#if ...
  BYTE                    spare3[8];
  BYTE                    HiberFileType;
  BOOLEAN                 AoAcConnectivitySupported;
#else
  BYTE                    spare3[6];
#endif
  BOOLEAN                 SystemBatteriesPresent;
  BOOLEAN                 BatteriesAreShortTerm;
  BATTERY_REPORTING_SCALE BatteryScale[3];
  SYSTEM_POWER_STATE      AcOnLineWake;
  SYSTEM_POWER_STATE      SoftLidWake;
  SYSTEM_POWER_STATE      RtcWake;
  SYSTEM_POWER_STATE      MinDeviceWakeState;
  SYSTEM_POWER_STATE      DefaultLowLatencyWake;
} SYSTEM_POWER_CAPABILITIES, *PSYSTEM_POWER_CAPABILITIES;