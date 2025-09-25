typedef struct DXGI_DDI_ARG_QUERYRESOURCERESIDENCY {
  [in]  DXGI_DDI_HDEVICE         hDevice;
  [in]  const DXGI_DDI_HRESOURCE *pResources;
  [out] DXGI_DDI_RESIDENCY       *pStatus;
  [in]  SIZE_T                   Resources;
} DXGI_DDI_ARG_QUERYRESOURCERESIDENCY;