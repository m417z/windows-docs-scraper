typedef struct tagKS_VIDEOINFOHEADER {
  RECT                rcSource;
  RECT                rcTarget;
  DWORD               dwBitRate;
  DWORD               dwBitErrorRate;
  REFERENCE_TIME      AvgTimePerFrame;
  KS_BITMAPINFOHEADER bmiHeader;
} KS_VIDEOINFOHEADER, *PKS_VIDEOINFOHEADER;