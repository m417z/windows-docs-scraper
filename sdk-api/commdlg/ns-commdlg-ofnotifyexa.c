typedef struct _OFNOTIFYEXA {
  NMHDR           hdr;
  LPOPENFILENAMEA lpOFN;
  LPVOID          psf;
  LPVOID          pidl;
} OFNOTIFYEXA, *LPOFNOTIFYEXA;