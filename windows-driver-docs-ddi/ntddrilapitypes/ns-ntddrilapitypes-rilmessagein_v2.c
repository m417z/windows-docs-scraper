typedef struct RILMESSAGEIN_V2 {
  DWORD      cbSize;
  DWORD      dwExecutor;
  HUICCAPP   hUiccApp;
  DWORD      dwAckID;
  RILMESSAGE rm;
  DWORD      dwFlags;
} RILMESSAGEIN_V2, RILMESSAGEIN, *LPRILMESSAGEIN;