HRESULT CreateFontResource(
  [in]          IStream            *acquiredStream,
  [in]          XPS_FONT_EMBEDDING fontEmbedding,
  [in]          IOpcPartUri        *partUri,
  [in]          BOOL               isObfSourceStream,
  [out, retval] IXpsOMFontResource **fontResource
);