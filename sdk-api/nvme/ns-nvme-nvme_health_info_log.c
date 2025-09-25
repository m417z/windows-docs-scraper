typedef struct {
  union {
    struct {
      UCHAR AvailableSpaceLow : 1;
      UCHAR TemperatureThreshold : 1;
      UCHAR ReliabilityDegraded : 1;
      UCHAR ReadOnly : 1;
      UCHAR VolatileMemoryBackupDeviceFailed : 1;
      UCHAR Reserved : 3;
    } DUMMYSTRUCTNAME;
    UCHAR AsUchar;
  } CriticalWarning;
  UCHAR  Temperature[2];
  UCHAR  AvailableSpare;
  UCHAR  AvailableSpareThreshold;
  UCHAR  PercentageUsed;
  UCHAR  Reserved0[26];
  UCHAR  DataUnitRead[16];
  UCHAR  DataUnitWritten[16];
  UCHAR  HostReadCommands[16];
  UCHAR  HostWrittenCommands[16];
  UCHAR  ControllerBusyTime[16];
  UCHAR  PowerCycle[16];
  UCHAR  PowerOnHours[16];
  UCHAR  UnsafeShutdowns[16];
  UCHAR  MediaErrors[16];
  UCHAR  ErrorInfoLogEntryCount[16];
  ULONG  WarningCompositeTemperatureTime;
  ULONG  CriticalCompositeTemperatureTime;
  USHORT TemperatureSensor1;
  USHORT TemperatureSensor2;
  USHORT TemperatureSensor3;
  USHORT TemperatureSensor4;
  USHORT TemperatureSensor5;
  USHORT TemperatureSensor6;
  USHORT TemperatureSensor7;
  USHORT TemperatureSensor8;
  UCHAR  Reserved1[296];
} NVME_HEALTH_INFO_LOG, *PNVME_HEALTH_INFO_LOG;