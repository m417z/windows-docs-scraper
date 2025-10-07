HRESULT IWICImagingFactory_CreateBitmapFromMemory_Proxy(
  _In_  IWICImagingFactory    *pFactory,
  _In_  UINT                  uiWidth,
  _In_  UINT                  uiHeight,
  _In_  REFWICPixelFormatGUID pixelFormat,
  _In_  UINT                  cbStride,
  _In_  UINT                  cbBufferSize,
  _In_  BYTE                  *pbBuffer,
  _Out_ IWICBitmap            **ppIBitmap
);