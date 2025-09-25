HRESULT CreateCustomFontFileReference(
  [in]  void const            *fontFileReferenceKey,
        UINT32                fontFileReferenceKeySize,
        IDWriteFontFileLoader *fontFileLoader,
  [out] IDWriteFontFile       **fontFile
);