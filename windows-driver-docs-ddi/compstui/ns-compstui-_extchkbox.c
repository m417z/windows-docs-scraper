typedef struct _EXTCHKBOX {
  WORD      cbSize;
  WORD      Flags;
  LPTSTR    pTitle;
  LPTSTR    pSeparator;
  LPTSTR    pCheckedName;
  ULONG_PTR IconID;
  WORD      wReserved[4];
  ULONG_PTR dwReserved[2];
} EXTCHKBOX, *PEXTCHKBOX;