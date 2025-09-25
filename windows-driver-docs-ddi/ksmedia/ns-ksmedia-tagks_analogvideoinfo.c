typedef struct tagKS_AnalogVideoInfo {
  RECT           rcSource;
  RECT           rcTarget;
  DWORD          dwActiveWidth;
  DWORD          dwActiveHeight;
  REFERENCE_TIME AvgTimePerFrame;
} KS_ANALOGVIDEOINFO, *PKS_ANALOGVIDEOINFO;