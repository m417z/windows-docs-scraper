typedef struct tagVMRPRESENTATIONINFO {
  DWORD                dwFlags;
  LPDIRECTDRAWSURFACE7 lpSurf;
  REFERENCE_TIME       rtStart;
  REFERENCE_TIME       rtEnd;
  SIZE                 szAspectRatio;
  RECT                 rcSrc;
  RECT                 rcDst;
  DWORD                dwTypeSpecificFlags;
  DWORD                dwInterlaceFlags;
} VMRPRESENTATIONINFO;