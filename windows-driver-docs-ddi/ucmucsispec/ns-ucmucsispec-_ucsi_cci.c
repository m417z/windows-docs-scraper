typedef union _UCSI_CCI {
  UINT32 AsUInt32;
  struct {
    UINT32 ConnectorChangeIndicator : 7;
    UINT32 DataLength : 8;
    UINT32 NotSupportedIndicator : 1;
    UINT32 CancelCompletedIndicator : 1;
    UINT32 ResetCompletedIndicator : 1;
    UINT32 BusyIndicator : 1;
    UINT32 AcknowledgeCommandIndicator : 1;
    UINT32 ErrorIndicator : 1;
    UINT32 CommandCompletedIndicator : 1;
  };
} UCSI_CCI, *PUCSI_CCI;