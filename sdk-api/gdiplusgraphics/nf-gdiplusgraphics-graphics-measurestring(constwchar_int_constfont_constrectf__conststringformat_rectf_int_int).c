Status MeasureString(
  const WCHAR        *string,
  INT                length,
  const Font         *font,
  const RectF &      layoutRect,
  const StringFormat *stringFormat,
  RectF              *boundingBox,
  INT                *codepointsFitted,
  INT                *linesFilled
);