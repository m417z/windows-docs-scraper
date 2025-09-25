Status MeasureCharacterRanges(
  [in]      const WCHAR        *string,
  [in]      INT                length,
  [in]      const Font         *font,
  [in, ref] const RectF &      layoutRect,
  [in]      const StringFormat *stringFormat,
  [in]      INT                regionCount,
  [out]     Region             *regions
);