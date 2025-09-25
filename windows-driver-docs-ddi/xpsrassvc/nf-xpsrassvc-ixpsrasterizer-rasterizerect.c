HRESULT RasterizeRect(
  [in]            INT                                x,
  [in]            INT                                y,
  [in]            INT                                width,
  [in]            INT                                height,
  [in, optional]  IXpsRasterizerNotificationCallback *notificationCallback,
  [out, optional] IWICBitmap                         **bitmap
);