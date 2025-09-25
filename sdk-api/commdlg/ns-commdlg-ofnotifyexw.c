typedef struct _OFNOTIFYEXW {
  NMHDR           hdr;
  LPOPENFILENAMEW lpOFN;
  LPVOID          psf;
  LPVOID          pidl;
} OFNOTIFYEXW, *LPOFNOTIFYEXW;