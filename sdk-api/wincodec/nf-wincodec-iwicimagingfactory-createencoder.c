HRESULT CreateEncoder(
  [in]           REFGUID           guidContainerFormat,
  [in, optional] const GUID        *pguidVendor,
  [out, retval]  IWICBitmapEncoder **ppIEncoder
);