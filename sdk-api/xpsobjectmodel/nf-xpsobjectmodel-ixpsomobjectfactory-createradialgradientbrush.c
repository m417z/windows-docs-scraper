HRESULT CreateRadialGradientBrush(
  [in]          IXpsOMGradientStop        *gradStop1,
  [in]          IXpsOMGradientStop        *gradStop2,
  [in]          const XPS_POINT           *centerPoint,
  [in]          const XPS_POINT           *gradientOrigin,
  [in]          const XPS_SIZE            *radiiSizes,
  [out, retval] IXpsOMRadialGradientBrush **radialGradientBrush
);