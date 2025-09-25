typedef union _UCSI_SET_PDR_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 PowerDirectionRole : 3;
  };
} UCSI_SET_PDR_COMMAND, *PUCSI_SET_PDR_COMMAND;