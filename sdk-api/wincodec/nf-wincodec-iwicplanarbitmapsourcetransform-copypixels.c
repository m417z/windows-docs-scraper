HRESULT CopyPixels(
  [in] const WICRect             *prcSource,
       UINT                      uiWidth,
       UINT                      uiHeight,
       WICBitmapTransformOptions dstTransform,
  [in] WICPlanarOptions          dstPlanarOptions,
       const WICBitmapPlane      *pDstPlanes,
       UINT                      cPlanes
);