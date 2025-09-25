typedef struct tagKS_VIDEOINFO {
  RECT                rcSource;
  RECT                rcTarget;
  DWORD               dwBitRate;
  DWORD               dwBitErrorRate;
  REFERENCE_TIME      AvgTimePerFrame;
  KS_BITMAPINFOHEADER bmiHeader;
  union {
    KS_RGBQUAD       bmiColors[KS_iPALETTE_COLORS];
    DWORD            dwBitMasks[KS_iMASK_COLORS];
    KS_TRUECOLORINFO TrueColorInfo;
  };
} KS_VIDEOINFO, *PKS_VIDEOINFO;