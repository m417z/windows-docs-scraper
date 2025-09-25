typedef struct DXGI_DDI_ARG_SETRESOURCEPRIORITY {
  [in] DXGI_DDI_HDEVICE   hDevice;
  [in] DXGI_DDI_HRESOURCE hResource;
  [in] UINT               Priority;
} DXGI_DDI_ARG_SETRESOURCEPRIORITY;