typedef struct RILMESSAGEIN_V1 {
  DWORD      cbSize;
  DWORD      dwExecutor;
  HUICCAPP   hUiccApp;
  DWORD      dwAckID;
  RILMESSAGE rm;
} RILMESSAGEIN_V1;