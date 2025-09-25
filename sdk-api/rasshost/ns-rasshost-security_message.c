typedef struct _SECURITY_MESSAGE {
  DWORD dwMsgId;
  HPORT hPort;
  DWORD dwError;
  CHAR  UserName[UNLEN + 1];
  CHAR  Domain[DNLEN + 1];
} SECURITY_MESSAGE, *PSECURITY_MESSAGE;