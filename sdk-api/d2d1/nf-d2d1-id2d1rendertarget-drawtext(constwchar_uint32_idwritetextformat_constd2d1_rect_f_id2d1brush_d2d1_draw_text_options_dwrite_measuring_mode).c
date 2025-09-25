void DrawText(
  [in] const WCHAR            *string,
       UINT32                 stringLength,
  [in] IDWriteTextFormat      *textFormat,
  [in] const D2D1_RECT_F      *layoutRect,
  [in] ID2D1Brush             *defaultFillBrush,
       D2D1_DRAW_TEXT_OPTIONS options,
       DWRITE_MEASURING_MODE  measuringMode
);