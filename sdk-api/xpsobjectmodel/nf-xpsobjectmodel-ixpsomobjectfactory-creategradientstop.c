HRESULT CreateGradientStop(
  [in]          const XPS_COLOR            *color,
  [in]          IXpsOMColorProfileResource *colorProfile,
  [in]          FLOAT                      offset,
  [out, retval] IXpsOMGradientStop         **gradientStop
);