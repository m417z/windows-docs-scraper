typedef struct tagMEASUREITEMSTRUCT {
  UINT      CtlType;
  UINT      CtlID;
  UINT      itemID;
  UINT      itemWidth;
  UINT      itemHeight;
  ULONG_PTR itemData;
} MEASUREITEMSTRUCT, *PMEASUREITEMSTRUCT, *LPMEASUREITEMSTRUCT;