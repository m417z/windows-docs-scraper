typedef struct HBA_FCPBinding2 {
  HBA_UINT32           NumberOfEntries;
  HBA_FCPBINDINGENTRY2 entry[1];
} HBA_FCPBINDING2, *PHBA_FCPBINDING2;