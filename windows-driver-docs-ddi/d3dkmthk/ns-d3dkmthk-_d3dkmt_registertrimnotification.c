typedef struct _D3DKMT_REGISTERTRIMNOTIFICATION {
  [in]  LUID                               AdapterLuid;
  [in]  D3DKMT_HANDLE                      hDevice;
  [in]  PFND3DKMT_TRIMNOTIFICATIONCALLBACK Callback;
  [in]  VOID                               *Context;
  [out] VOID                               *Handle;
} D3DKMT_REGISTERTRIMNOTIFICATION;