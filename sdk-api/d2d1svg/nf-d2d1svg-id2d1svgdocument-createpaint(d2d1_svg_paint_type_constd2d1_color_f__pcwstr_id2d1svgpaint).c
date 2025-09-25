HRESULT CreatePaint(
                 D2D1_SVG_PAINT_TYPE  paintType,
  [ref]          const D2D1_COLOR_F & color,
  [in, optional] PCWSTR               id,
  [out]          ID2D1SvgPaint        **paint
);