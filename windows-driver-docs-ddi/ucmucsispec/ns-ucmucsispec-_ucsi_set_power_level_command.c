typedef union _UCSI_SET_POWER_LEVEL_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 SourceOrSink : 1;
    UINT64 UsbPdMaxPowerIn500mW : 8;
    UINT64 UsbTypeCCurrent : 2;
  };
} UCSI_SET_POWER_LEVEL_COMMAND, *PUCSI_SET_POWER_LEVEL_COMMAND;