typedef struct DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES {
  [in] DXGI_DDI_HDEVICE         hDevice;
  [in] const DXGI_DDI_HRESOURCE *pResources;
  [in] UINT                     Resources;
} DXGI_DDI_ARG_ROTATE_RESOURCE_IDENTITIES;