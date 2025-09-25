typedef union _UCSI_SET_NEW_CAM_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 EnterOrExit : 1;
    UINT64 NewCam : 8;
    UINT64 AmSpecific : 32;
  };
} UCSI_SET_NEW_CAM_COMMAND, *PUCSI_SET_NEW_CAM_COMMAND;