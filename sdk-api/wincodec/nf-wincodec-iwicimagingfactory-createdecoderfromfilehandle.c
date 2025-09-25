HRESULT CreateDecoderFromFileHandle(
  [in]          ULONG_PTR         hFile,
  [in]          const GUID        *pguidVendor,
  [in]          WICDecodeOptions  metadataOptions,
  [out, retval] IWICBitmapDecoder **ppIDecoder
);