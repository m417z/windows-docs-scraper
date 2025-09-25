typedef struct _D3DKMT_CONFIGURESHAREDRESOURCE {
  [in] D3DKMT_HANDLE hDevice;
  [in] D3DKMT_HANDLE hResource;
  [in] BOOLEAN       IsDwm;
  [in] HANDLE        hProcess;
  [in] BOOLEAN       AllowAccess;
} D3DKMT_CONFIGURESHAREDRESOURCE;