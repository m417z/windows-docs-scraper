typedef struct tagPAGESET {
  ULONG     cbStruct;
  BOOL      fOddPages;
  BOOL      fEvenPages;
  ULONG     cPageRange;
  PAGERANGE rgPages[1];
} PAGESET;