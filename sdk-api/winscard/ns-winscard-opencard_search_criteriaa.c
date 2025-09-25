typedef struct {
  DWORD          dwStructSize;
  LPSTR          lpstrGroupNames;
  DWORD          nMaxGroupNames;
  LPCGUID        rgguidInterfaces;
  DWORD          cguidInterfaces;
  LPSTR          lpstrCardNames;
  DWORD          nMaxCardNames;
  LPOCNCHKPROC   lpfnCheck;
  LPOCNCONNPROCA lpfnConnect;
  LPOCNDSCPROC   lpfnDisconnect;
  LPVOID         pvUserData;
  DWORD          dwShareMode;
  DWORD          dwPreferredProtocols;
} OPENCARD_SEARCH_CRITERIAA, *POPENCARD_SEARCH_CRITERIAA, *LPOPENCARD_SEARCH_CRITERIAA;