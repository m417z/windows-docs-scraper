typedef struct RILMSGDCS {
  DWORD               cbSize;
  DWORD               dwParams;
  RILMSGDCSTYPE       dwType;
  DWORD               dwFlags;
  RILMSGDCSMSGCLASS   dwMsgClass;
  RILMSGDCSALPHABET   dwAlphabet;
  RILMSGDCSINDICATION dwIndication;
  DWORD               dwLanguage;
} RILMSGDCS, *LPRILMSGDCS;