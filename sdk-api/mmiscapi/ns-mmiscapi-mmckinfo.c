typedef struct _MMCKINFO {
  FOURCC ckid;
  DWORD  cksize;
  FOURCC fccType;
  DWORD  dwDataOffset;
  DWORD  dwFlags;
} MMCKINFO, *PMMCKINFO, *NPMMCKINFO, *LPMMCKINFO;