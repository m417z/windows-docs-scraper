typedef struct _DD_RENDERMOCOMPDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_MOTIONCOMP_LOCAL lpMoComp;
  DWORD                dwNumBuffers;
  LPDDMOCOMPBUFFERINFO lpBufferInfo;
  DWORD                dwFunction;
  LPVOID               lpInputData;
  DWORD                dwInputDataSize;
  LPVOID               lpOutputData;
  DWORD                dwOutputDataSize;
  HRESULT              ddRVal;
} *PDD_RENDERMOCOMPDATA, DD_RENDERMOCOMPDATA;