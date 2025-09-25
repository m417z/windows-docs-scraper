HRESULT GetOutput(
  [in]          ULONG                         uiIndex,
  [in]          IMILBitmapEffectRenderContext *pContext,
  [in, out]     VARIANT_BOOL                  *pfModifyInPlace,
  [out, retval] IWICBitmapSource              **ppBitmapSource
);