Status MeasureString(
  [in]      const WCHAR        *string,
  [in]      INT                length,
  [in]      const Font         *font,
  [in, ref] const SizeF &      layoutRectSize,
  [in]      const StringFormat *stringFormat,
  [out]     SizeF              *size,
  [out]     INT                *codepointsFitted,
  [out]     INT                *linesFilled
);