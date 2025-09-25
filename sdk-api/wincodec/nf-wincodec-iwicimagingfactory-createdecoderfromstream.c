HRESULT CreateDecoderFromStream(
  [in]          IStream           *pIStream,
  [in]          const GUID        *pguidVendor,
  [in]          WICDecodeOptions  metadataOptions,
  [out, retval] IWICBitmapDecoder **ppIDecoder
);