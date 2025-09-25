typedef struct tag_SCRIPT_VISATTR {
  WORD uJustification : 4;
  WORD fClusterStart : 1;
  WORD fDiacritic : 1;
  WORD fZeroWidth : 1;
  WORD fReserved : 1;
  WORD fShapeReserved : 8;
} SCRIPT_VISATTR;