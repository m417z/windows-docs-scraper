typedef struct tagTVSORTCB {
  HTREEITEM    hParent;
  PFNTVCOMPARE lpfnCompare;
  LPARAM       lParam;
} TVSORTCB, *LPTVSORTCB;