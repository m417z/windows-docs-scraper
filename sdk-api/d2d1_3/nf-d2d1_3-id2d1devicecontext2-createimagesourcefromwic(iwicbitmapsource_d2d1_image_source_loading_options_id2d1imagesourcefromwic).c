HRESULT CreateImageSourceFromWic(
  [in]  IWICBitmapSource                  *wicBitmapSource,
        D2D1_IMAGE_SOURCE_LOADING_OPTIONS loadingOptions,
  [out] ID2D1ImageSourceFromWic           **imageSource
);