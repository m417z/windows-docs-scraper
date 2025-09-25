typedef struct _OFNOTIFYA {
  NMHDR           hdr;
  LPOPENFILENAMEA lpOFN;
  LPSTR           pszFile;
} OFNOTIFYA, *LPOFNOTIFYA;