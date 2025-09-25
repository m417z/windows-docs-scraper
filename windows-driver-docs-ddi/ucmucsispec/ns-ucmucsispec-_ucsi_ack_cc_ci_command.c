typedef union _UCSI_ACK_CC_CI_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorChangeAcknowledge : 1;
    UINT64 CommandCompletedAcknowledge : 1;
  };
} UCSI_ACK_CC_CI_COMMAND, *PUCSI_ACK_CC_CI_COMMAND;