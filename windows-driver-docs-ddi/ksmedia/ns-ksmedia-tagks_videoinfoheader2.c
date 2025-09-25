typedef struct tagKS_VIDEOINFOHEADER2 {
  RECT                rcSource;
  RECT                rcTarget;
  DWORD               dwBitRate;
  DWORD               dwBitErrorRate;
  REFERENCE_TIME      AvgTimePerFrame;
  DWORD               dwInterlaceFlags;
  DWORD               dwCopyProtectFlags;
  DWORD               dwPictAspectRatioX;
  DWORD               dwPictAspectRatioY;
  union {
    DWORD dwControlFlags;
    DWORD dwReserved1;
  };
  DWORD               dwReserved2;
  KS_BITMAPINFOHEADER bmiHeader;
} KS_VIDEOINFOHEADER2, *PKS_VIDEOINFOHEADER2;