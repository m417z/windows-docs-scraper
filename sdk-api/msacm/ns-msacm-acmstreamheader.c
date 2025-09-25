typedef struct tACMSTREAMHEADER {
  DWORD     cbStruct;
  DWORD     fdwStatus;
  DWORD_PTR dwUser;
  LPBYTE    pbSrc;
  DWORD     cbSrcLength;
  DWORD     cbSrcLengthUsed;
  DWORD_PTR dwSrcUser;
  LPBYTE    pbDst;
  DWORD     cbDstLength;
  DWORD     cbDstLengthUsed;
  DWORD_PTR dwDstUser;
  DWORD     dwReservedDriver[_DRVRESERVED];
} ACMSTREAMHEADER, *PACMSTREAMHEADER, *LPACMSTREAMHEADER;