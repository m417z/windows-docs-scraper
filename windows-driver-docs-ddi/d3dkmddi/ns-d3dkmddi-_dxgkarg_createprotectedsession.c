typedef struct _DXGKARG_CREATEPROTECTEDSESSION {
  HANDLE hProtectedSession;
  PVOID  pPrivateDriverData;
  UINT   PrivateDriverDataSize;
} DXGKARG_CREATEPROTECTEDSESSION;