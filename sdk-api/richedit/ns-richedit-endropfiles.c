typedef struct _endropfiles {
  NMHDR  nmhdr;
  HANDLE hDrop;
  LONG   cp;
  BOOL   fProtected;
} ENDROPFILES;