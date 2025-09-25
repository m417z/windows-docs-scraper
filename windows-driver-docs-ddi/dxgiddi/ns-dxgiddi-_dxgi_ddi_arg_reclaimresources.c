typedef struct _DXGI_DDI_ARG_RECLAIMRESOURCES {
  [in]  DXGI_DDI_HDEVICE         hDevice;
  [in]  const DXGI_DDI_HRESOURCE *pResources;
  [out] BOOL                     *pDiscarded;
  [in]  UINT                     Resources;
} DXGI_DDI_ARG_RECLAIMRESOURCES;