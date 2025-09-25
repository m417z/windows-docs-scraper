typedef struct HBA_FCPBinding {
  HBA_UINT32          NumberOfEntries;
  HBA_FCPBINDINGENTRY entry[1];
} HBA_FCPBINDING, *PHBA_FCPBINDING;