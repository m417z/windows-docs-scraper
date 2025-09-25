typedef struct _CPSUICBPARAM {
  WORD      cbSize;
  WORD      Reason;
  HWND      hDlg;
  POPTITEM  pOptItem;
  WORD      cOptItem;
  WORD      Flags;
  POPTITEM  pCurItem;
  union {
    LONG   OldSel;
    LPTSTR pOldSel;
  } DUMMYUNIONNAME;
  ULONG_PTR UserData;
  ULONG_PTR Result;
} CPSUICBPARAM, *PCPSUICBPARAM;