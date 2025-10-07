typedef struct tagAPPHELP_DATA {
  DWORD  dwFlags;
  DWORD  dwSeverity;
  DWORD  dwHTMLHelpID;
  LPTSTR szAppName;
  TAGREF trExe;
  LPTSTR szURL;
  LPTSTR szLink;
  LPTSTR szAppTitle;
  LPTSTR szContact;
  LPTSTR szDetails;
  DWORD  dwData;
  BOOL   bSPEntry;
} APPHELP_DATA, *PAPPHELP_DATA;