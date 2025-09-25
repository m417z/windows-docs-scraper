typedef union _UCSI_GET_ALTERNATE_MODES_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 Recipient : 3;
    UINT64 ConnectorNumber : 7;
    UINT64 AlternateModeOffset : 8;
    UINT64 NumberOfAlternateModes : 2;
  };
} UCSI_GET_ALTERNATE_MODES_COMMAND, *PUCSI_GET_ALTERNATE_MODES_COMMAND;