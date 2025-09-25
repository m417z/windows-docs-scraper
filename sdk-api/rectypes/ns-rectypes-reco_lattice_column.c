typedef struct tagRECO_LATTICE_COLUMN {
  ULONG                   key;
  RECO_LATTICE_PROPERTIES cpProp;
  ULONG                   cStrokes;
  ULONG                   *pStrokes;
  ULONG                   cLatticeElements;
  RECO_LATTICE_ELEMENT    *pLatticeElements;
} RECO_LATTICE_COLUMN;