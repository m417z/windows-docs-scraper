typedef struct SMHBA_TargetMapping {
  HBA_UINT32      NumberOfEntries;
  SMHBA_SCSIENTRY entry[1];
} SMHBA_TARGETMAPPING, *PSMHBA_TARGETMAPPING;