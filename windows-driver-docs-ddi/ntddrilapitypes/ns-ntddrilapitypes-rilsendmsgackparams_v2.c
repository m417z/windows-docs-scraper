typedef struct RILSENDMSGACKPARAMS_V2 {
  DWORD           cbSize;
  DWORD           dwExecutor;
  HUICCAPP        hUiccApp;
  DWORD           dwAckID;
  RILMSGACKSTATUS dwMsgStatus;
  RILSMSFORMAT    dwSmsFormat;
  DWORD           dwOptions;
} RILSENDMSGACKPARAMS_V2, RILSENDMSGACKPARAMS, *LPRILSENDMSGACKPARAMS;