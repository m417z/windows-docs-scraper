typedef struct _tableRowParms {
    BYTE  cbRow;
    BYTE  cbCell;
    BYTE  cCell;
    BYTE  cRow;
    LONG  dxCellMargin;
    LONG  dxIndent;
    LONG  dyHeight;
  3 DWORD nAlignment : 3;
  1 DWORD fRTL : 1;
  1 DWORD fKeep : 1;
  1 DWORD fKeepFollow : 1;
  1 DWORD fWrap : 1;
  1 DWORD fIdentCells : 1;
    LONG  cpStartRow;
    BYTE  bTableLevel;
    BYTE  iCell;
} TABLEROWPARMS;