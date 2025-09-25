typedef struct _OFNOTIFYW {
  NMHDR           hdr;
  LPOPENFILENAMEW lpOFN;
  LPWSTR          pszFile;
} OFNOTIFYW, *LPOFNOTIFYW;