struct IDARG_IN_SWAPCHAINSETDEVICE2 {
  IDDCX_SWAPCHAIN_DEVICE_TYPE Type;
  union {
    IDXGIDevice  *pDxgiDevice;
    ID3D12Device *pD3d12Device;
  } Device;
};