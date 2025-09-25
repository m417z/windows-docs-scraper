typedef struct RILSENDMSGACKPARAMS_V1 {
  DWORD           cbSize;
  DWORD           dwExecutor;
  HUICCAPP        hUiccApp;
  DWORD           dwAckID;
  RILMSGACKSTATUS dwMsgStatus;
} RILSENDMSGACKPARAMS_V1;