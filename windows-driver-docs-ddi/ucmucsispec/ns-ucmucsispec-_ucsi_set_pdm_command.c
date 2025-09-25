typedef union _UCSI_SET_PDM_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 PowerDirectionMode : 3;
  };
} UCSI_SET_PDM_COMMAND, *PUCSI_SET_PDM_COMMAND;