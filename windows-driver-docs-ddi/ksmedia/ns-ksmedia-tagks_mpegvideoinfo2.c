typedef struct tagKS_MPEGVIDEOINFO2 {
  KS_VIDEOINFOHEADER2 hdr;
  DWORD               dwStartTimeCode;
  DWORD               cbSequenceHeader;
  DWORD               dwProfile;
  DWORD               dwLevel;
  DWORD               dwFlags;
  DWORD               bSequenceHeader[1];
} KS_MPEGVIDEOINFO2, *PKS_MPEGVIDEOINFO2;