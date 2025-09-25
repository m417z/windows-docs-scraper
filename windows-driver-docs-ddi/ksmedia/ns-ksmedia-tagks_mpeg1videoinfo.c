typedef struct tagKS_MPEG1VIDEOINFO {
  KS_VIDEOINFOHEADER hdr;
  DWORD              dwStartTimeCode;
  DWORD              cbSequenceHeader;
  BYTE               bSequenceHeader[1];
} KS_MPEG1VIDEOINFO, *PKS_MPEG1VIDEOINFO;