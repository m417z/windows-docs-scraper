typedef struct _KERNDATA {
  DWORD          dwSize;
  DWORD          dwKernPairNum;
  FD_KERNINGPAIR KernPair[1];
} KERNDATA, *PKERNDATA;