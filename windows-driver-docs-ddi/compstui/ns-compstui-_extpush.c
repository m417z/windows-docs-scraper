typedef struct _EXTPUSH {
  WORD      cbSize;
  WORD      Flags;
  LPTSTR    pTitle;
  union {
    DLGPROC DlgProc;
    FARPROC pfnCallBack;
  } DUMMYUNIONNAME;
  ULONG_PTR IconID;
  union {
    WORD   DlgTemplateID;
    HANDLE hDlgTemplate;
  } DUMMYUNIONNAME2;
  ULONG_PTR dwReserved[3];
} EXTPUSH, *PEXTPUSH;