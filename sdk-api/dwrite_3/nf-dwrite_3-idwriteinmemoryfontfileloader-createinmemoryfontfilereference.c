HRESULT CreateInMemoryFontFileReference(
                 IDWriteFactory  *factory,
  [in]           void const      *fontData,
                 UINT32          fontDataSize,
  [in, optional] IUnknown        *ownerObject,
  [out]          IDWriteFontFile **fontFile
);