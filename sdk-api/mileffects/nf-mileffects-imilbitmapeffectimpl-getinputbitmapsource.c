HRESULT GetInputBitmapSource(
  [in]          ULONG                         uiIndex,
  [in]          IMILBitmapEffectRenderContext *pRenderContext,
  [in, out]     VARIANT_BOOL                  *pfModifyInPlace,
  [out, retval] IWICBitmapSource              **ppBitmapSource
);