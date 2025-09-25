typedef union _UCSI_CONNECTOR_RESET_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 HardReset : 1;
  };
} UCSI_CONNECTOR_RESET_COMMAND, *PUCSI_CONNECTOR_RESET_COMMAND;