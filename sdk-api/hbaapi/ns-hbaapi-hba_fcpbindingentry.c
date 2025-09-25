typedef struct HBA_FCPBindingEntry {
  HBA_FCPBINDINGTYPE type;
  HBA_SCSIID         ScsiId;
  HBA_FCPID          FcpId;
  HBA_UINT32         FcId;
} HBA_FCPBINDINGENTRY, *PHBA_FCPBINDINGENTRY;