typedef struct tagKS_AMVPDATAINFO {
  DWORD          dwSize;
  DWORD          dwMicrosecondsPerField;
  KS_AMVPDIMINFO amvpDimInfo;
  DWORD          dwPictAspectRatioX;
  DWORD          dwPictAspectRatioY;
  BOOL           bEnableDoubleClock;
  BOOL           bEnableVACT;
  BOOL           bDataIsInterlaced;
  LONG           lHalfLinesOdd;
  BOOL           bFieldPolarityInverted;
  DWORD          dwNumLinesInVREF;
  LONG           lHalfLinesEven;
  DWORD          dwReserved1;
} KS_AMVPDATAINFO, *PKS_AMVPDATAINFO;