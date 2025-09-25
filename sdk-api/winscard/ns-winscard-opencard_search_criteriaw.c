typedef struct {
  DWORD          dwStructSize;
  LPWSTR         lpstrGroupNames;
  DWORD          nMaxGroupNames;
  LPCGUID        rgguidInterfaces;
  DWORD          cguidInterfaces;
  LPWSTR         lpstrCardNames;
  DWORD          nMaxCardNames;
  LPOCNCHKPROC   lpfnCheck;
  LPOCNCONNPROCW lpfnConnect;
  LPOCNDSCPROC   lpfnDisconnect;
  LPVOID         pvUserData;
  DWORD          dwShareMode;
  DWORD          dwPreferredProtocols;
} OPENCARD_SEARCH_CRITERIAW, *POPENCARD_SEARCH_CRITERIAW, *LPOPENCARD_SEARCH_CRITERIAW;