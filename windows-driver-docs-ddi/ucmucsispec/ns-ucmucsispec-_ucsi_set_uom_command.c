typedef union _UCSI_SET_UOM_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 UsbOperationMode : 3;
  };
} UCSI_SET_UOM_COMMAND, *PUCSI_SET_UOM_COMMAND;