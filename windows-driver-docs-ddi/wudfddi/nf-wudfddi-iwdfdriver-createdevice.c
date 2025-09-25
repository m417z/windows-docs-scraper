HRESULT CreateDevice(
  [in]           IWDFDeviceInitialize *pDeviceInit,
  [in, optional] IUnknown             *pCallbackInterface,
  [out]          IWDFDevice           **ppDevice
);