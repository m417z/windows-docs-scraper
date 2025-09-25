HRESULT CreateLinearGradientBrush(
  [in]          IXpsOMGradientStop        *gradStop1,
  [in]          IXpsOMGradientStop        *gradStop2,
  [in]          const XPS_POINT           *startPoint,
  [in]          const XPS_POINT           *endPoint,
  [out, retval] IXpsOMLinearGradientBrush **linearGradientBrush
);