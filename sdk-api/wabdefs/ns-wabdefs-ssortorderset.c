typedef struct _SSortOrderSet {
  ULONG      cSorts;
  ULONG      cCategories;
  ULONG      cExpanded;
  SSortOrder aSort[MAPI_DIM];
} SSortOrderSet, *LPSSortOrderSet;