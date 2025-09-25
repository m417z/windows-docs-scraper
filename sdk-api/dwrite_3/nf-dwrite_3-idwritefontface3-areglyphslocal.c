HRESULT AreGlyphsLocal(
  [in]  UINT16 const *glyphIndices,
        UINT32       glyphCount,
        BOOL         enqueueIfNotLocal,
  [out] BOOL         *isLocal
);