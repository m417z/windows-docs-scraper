typedef struct _DLGPAGE {
  WORD      cbSize;
  WORD      Flags;
  DLGPROC   DlgProc;
  LPTSTR    pTabName;
  ULONG_PTR IconID;
  union {
    WORD   DlgTemplateID;
    HANDLE hDlgTemplate;
  } DUMMYUNIONNAME;
} DLGPAGE, *PDLGPAGE;