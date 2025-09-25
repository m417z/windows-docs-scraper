typedef union _UCSI_GET_CAM_SUPPORTED_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
  };
} UCSI_GET_CAM_SUPPORTED_COMMAND, *PUCSI_GET_CAM_SUPPORTED_COMMAND;