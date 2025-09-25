typedef struct _D3DKMT_GETSHAREDRESOURCEADAPTERLUID {
  [in]  D3DKMT_HANDLE hGlobalShare;
  [in]  HANDLE        hNtHandle;
  [out] LUID          AdapterLuid;
} D3DKMT_GETSHAREDRESOURCEADAPTERLUID;