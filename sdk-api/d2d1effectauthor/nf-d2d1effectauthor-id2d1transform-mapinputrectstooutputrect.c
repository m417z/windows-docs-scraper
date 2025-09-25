HRESULT MapInputRectsToOutputRect(
  [in] const D2D1_RECT_L *inputRects,
  [in] const D2D1_RECT_L *inputOpaqueSubRects,
       UINT32            inputRectCount,
       D2D1_RECT_L       *outputRect,
       D2D1_RECT_L       *outputOpaqueSubRect
);