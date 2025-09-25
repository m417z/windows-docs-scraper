HRESULT CreateDecoderFromFilename(
  [in]          LPCWSTR           wzFilename,
  [in]          const GUID        *pguidVendor,
  [in]          DWORD             dwDesiredAccess,
  [in]          WICDecodeOptions  metadataOptions,
  [out, retval] IWICBitmapDecoder **ppIDecoder
);