typedef struct RILMESSAGEINFO {
  DWORD            cbSize;
  HUICCAPP         hUiccApp;
  DWORD            dwParams;
  DWORD            dwIndex;
  RILMESSAGESTATUS dwStatus;
  RILMESSAGE       rmMessage;
} RILMESSAGEINFO, *LPRILMESSAGEINFO;