typedef struct _DXGI_DDI_ARG_OFFERRESOURCES {
  [in] DXGI_DDI_HDEVICE         hDevice;
  [in] const DXGI_DDI_HRESOURCE *pResources;
  [in] UINT                     Resources;
  [in] D3DDDI_OFFER_PRIORITY    Priority;
} DXGI_DDI_ARG_OFFERRESOURCES;