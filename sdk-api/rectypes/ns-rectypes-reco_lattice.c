typedef struct tagRECO_LATTICE {
  ULONG               ulColumnCount;
  RECO_LATTICE_COLUMN *pLatticeColumns;
  ULONG               ulPropertyCount;
  GUID                *pGuidProperties;
  ULONG               ulBestResultColumnCount;
  ULONG               *pulBestResultColumns;
  ULONG               *pulBestResultIndexes;
} RECO_LATTICE;