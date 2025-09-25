typedef struct _DD_ENDMOCOMPFRAMEDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_MOTIONCOMP_LOCAL lpMoComp;
  LPVOID               lpInputData;
  DWORD                dwInputDataSize;
  HRESULT              ddRVal;
} *PDD_ENDMOCOMPFRAMEDATA, DD_ENDMOCOMPFRAMEDATA;