void DrawText(
  [in]           const WCHAR            *string,
                 UINT32                 stringLength,
  [in]           IDWriteTextFormat      *textFormat,
  [in]           const D2D1_RECT_F      *layoutRect,
  [in, optional] ID2D1Brush             *defaultFillBrush,
  [in, optional] ID2D1SvgGlyphStyle     *svgGlyphStyle,
                 UINT32                 colorPaletteIndex,
                 D2D1_DRAW_TEXT_OPTIONS options,
                 DWRITE_MEASURING_MODE  measuringMode
);