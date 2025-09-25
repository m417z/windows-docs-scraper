typedef struct _SRowSet {
  ULONG cRows;
  SRow  aRow[MAPI_DIM];
} SRowSet, *LPSRowSet;