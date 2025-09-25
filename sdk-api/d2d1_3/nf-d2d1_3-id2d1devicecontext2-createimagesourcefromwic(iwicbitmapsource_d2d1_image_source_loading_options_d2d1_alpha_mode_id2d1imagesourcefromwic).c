HRESULT CreateImageSourceFromWic(
  [in]  IWICBitmapSource                  *wicBitmapSource,
        D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
        D2D1_ALPHA_MODE                   alphaMode,
  [out] ID2D1ImageSourceFromWic           **imageSource
);