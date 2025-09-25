typedef struct _DXVA_ProcAmpControlCaps {
  DWORD     Size;
  DWORD     InputPool;
  D3DFORMAT d3dOutputFormat;
  DWORD     ProcAmpControlProps;
  DWORD     VideoProcessingCaps;
} DXVA_ProcAmpControlCaps, *LPDXVA_ProcAmpControlCaps;