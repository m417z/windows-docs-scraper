HRESULT DoesSupportTransform(
  [in, out] UINT                      *puiWidth,
  [in, out] UINT                      *puiHeight,
            WICBitmapTransformOptions dstTransform,
            WICPlanarOptions          dstPlanarOptions,
  [in]      const WICPixelFormatGUID  *pguidDstFormats,
  [out]     WICBitmapPlaneDescription *pPlaneDescriptions,
            UINT                      cPlanes,
  [out]     BOOL                      *pfIsSupported
);