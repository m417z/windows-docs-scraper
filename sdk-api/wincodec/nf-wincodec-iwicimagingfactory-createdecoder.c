HRESULT CreateDecoder(
  [in]          REFGUID           guidContainerFormat,
  [in]          const GUID        *pguidVendor,
  [out, retval] IWICBitmapDecoder **ppIDecoder
);