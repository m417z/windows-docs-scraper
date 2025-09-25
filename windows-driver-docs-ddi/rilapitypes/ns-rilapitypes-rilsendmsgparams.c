typedef struct RILSENDMSGPARAMS {
  DWORD      dwExecutor;
  HUICCAPP   hUiccApp;
  RILMESSAGE rmMessage;
  DWORD      dwOptions;
} RILSENDMSGPARAMS, *LPRILSENDMSGPARAMS;