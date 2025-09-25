typedef struct _RILSUBSCRIBERINFO {
  DWORD                         cbSize;
  DWORD                         dwParams;
  RILADDRESS                    raAddress;
  WCHAR [MAXLENGTH_DESCRIPTION] wszDescription;
  RILSUBSCRIBERINFOSERVICE      dwService;
} RILSUBSCRIBERINFO, RILSUBSCRIBERINFO;