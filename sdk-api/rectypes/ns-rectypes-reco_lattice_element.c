typedef struct tagRECO_LATTICE_ELEMENT {
  RECO_SCORE              score;
  WORD                    type;
  BYTE                    *pData;
  ULONG                   ulNextColumn;
  ULONG                   ulStrokeNumber;
  RECO_LATTICE_PROPERTIES epProp;
} RECO_LATTICE_ELEMENT;