typedef struct _DD_BEGINMOCOMPFRAMEDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_MOTIONCOMP_LOCAL lpMoComp;
  PDD_SURFACE_LOCAL    lpDestSurface;
  DWORD                dwInputDataSize;
  LPVOID               lpInputData;
  DWORD                dwOutputDataSize;
  LPVOID               lpOutputData;
  HRESULT              ddRVal;
} *PDD_BEGINMOCOMPFRAMEDATA, DD_BEGINMOCOMPFRAMEDATA;