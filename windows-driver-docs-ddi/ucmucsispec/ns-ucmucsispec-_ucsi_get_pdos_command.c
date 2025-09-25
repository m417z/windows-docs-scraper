typedef union _UCSI_GET_PDOS_COMMAND {
  UINT64 AsUInt64;
  struct {
    UINT64 Command : 8;
    UINT64 DataLength : 8;
    UINT64 ConnectorNumber : 7;
    UINT64 PartnerPdo : 1;
    UINT64 PdoOffset : 8;
    UINT64 NumberOfPdos : 2;
    UINT64 SourceOrSinkPdos : 1;
    UINT64 SourceCapabilitiesType : 2;
  };
} UCSI_GET_PDOS_COMMAND, *PUCSI_GET_PDOS_COMMAND;