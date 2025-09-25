typedef struct {
  DWORD cbStruct;
  LONG  cClasses;
  DWORD offsetClass[1];
} DSQUERYCLASSLIST, *LPDSQUERYCLASSLIST;