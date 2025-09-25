HRESULT CreateImageResource(
  [in]          IStream             *acquiredStream,
  [in]          XPS_IMAGE_TYPE      contentType,
  [in]          IOpcPartUri         *partUri,
  [out, retval] IXpsOMImageResource **imageResource
);