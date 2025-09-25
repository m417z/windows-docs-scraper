typedef struct RILCALLMODIFICATIONINFO {
  DWORD                                   cbSize;
  DWORD                                   dwParams;
  DWORD                                   dwExecutor;
  DWORD                                   dwID;
  RILCALLMODIFICATIONINFOMODIFICATIONTYPE dwModificationType;
  RILCALLTYPE                             dwOldCallType;
  RILCALLTYPE                             dwNewCallType;
  RILADDRESS                              raAddress;
  RILALPHAIDENTIFIER                      aiIdentifier;
} RILCALLMODIFICATIONINFO, *LPRILCALLMODIFICATIONINFO;