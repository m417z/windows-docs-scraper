typedef struct _DXGKARG_NOTIFYWORKSUBMISSION {
  HANDLE                             hHwQueue;
  DXGKARG_NOTIFYWORKSUBMISSION_FLAGS Flags;
  BYTE                               pPrivateDriverData[D3DDDI_UMS_PDD_SIZE];
} DXGKARG_NOTIFYWORKSUBMISSION;