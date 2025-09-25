Status MeasureString(
  [in]      const WCHAR        *string,
  [in]      INT                length,
  [in]      const Font         *font,
  [in, ref] const PointF &     origin,
  [in]      const StringFormat *stringFormat,
  [out]     RectF              *boundingBox
);