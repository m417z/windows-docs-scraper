typedef struct tagHHNTRACK {
  NMHDR      hdr;
  PCSTR      pszCurUrl;
  int        idAction;
  HH_WINTYPE *phhWinType;
} HHNTRACK;