HRESULT GetSvgGlyphImage(
                 D2D1_POINT_2F           glyphOrigin,
  [in]           IDWriteFontFace         *fontFace,
                 FLOAT                   fontEmSize,
                 UINT16                  glyphIndex,
                 BOOL                    isSideways,
  [in, optional] const D2D1_MATRIX_3X2_F *worldTransform,
  [in, optional] ID2D1Brush              *defaultFillBrush,
  [in, optional] ID2D1SvgGlyphStyle      *svgGlyphStyle,
                 UINT32                  colorPaletteIndex,
  [out]          D2D1_MATRIX_3X2_F       *glyphTransform,
  [out]          ID2D1CommandList        **glyphImage
);