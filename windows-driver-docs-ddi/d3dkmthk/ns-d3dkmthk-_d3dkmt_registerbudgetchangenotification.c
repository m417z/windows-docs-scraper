typedef struct _D3DKMT_REGISTERBUDGETCHANGENOTIFICATION {
  [in]  D3DKMT_HANDLE                              hDevice;
  [in]  PFND3DKMT_BUDGETCHANGENOTIFICATIONCALLBACK Callback;
  [in]  VOID                                       *Context;
  [out] VOID                                       *Handle;
} D3DKMT_REGISTERBUDGETCHANGENOTIFICATION;