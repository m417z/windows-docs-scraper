void SM_GetLUNStatistics(
   [in, HBAType("HBA_SCSIID")] HBAScsiID                                     Lunit,
   [out, HBA_STATUS_QUALIFIERS] HBA_STATUS                                   HBAStatus,
   [out, HBAType("MS_SMHBA_PROTOCOLSTATISTICS")] MS_SMHBA_PROTOCOLSTATISTICS ProtocolStatistics
);