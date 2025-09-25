HRESULT TransformPoint(
  [in]      ULONG                         uiIndex,
  [in, out] MilPoint2D                    *p,
  [in]      VARIANT_BOOL                  fForwardTransform,
  [in]      IMILBitmapEffectRenderContext *pContext,
  [out]     VARIANT_BOOL                  *pfPointTransformed
);