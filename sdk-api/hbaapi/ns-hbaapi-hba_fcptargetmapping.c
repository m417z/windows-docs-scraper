typedef struct HBA_FCPTargetMapping {
  HBA_UINT32       NumberOfEntries;
  HBA_FCPSCSIENTRY entry[1];
} HBA_FCPTARGETMAPPING, *PHBA_FCPTARGETMAPPING;