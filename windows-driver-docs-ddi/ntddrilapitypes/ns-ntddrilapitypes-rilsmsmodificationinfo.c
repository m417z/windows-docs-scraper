typedef struct RILSMSMODIFICATIONINFO {
  DWORD              cbSize;
  DWORD              dwParams;
  DWORD              dwExecutor;
  DWORD              dwModificationType;
  RILADDRESS         raAddress;
  RILALPHAIDENTIFIER aiIdentifier;
} RILSMSMODIFICATIONINFO, *LPRILSMSMODIFICATIONINFO;