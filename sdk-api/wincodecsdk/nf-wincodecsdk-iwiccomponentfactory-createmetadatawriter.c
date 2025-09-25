HRESULT CreateMetadataWriter(
  [in]  REFGUID            guidMetadataFormat,
  [in]  const GUID         *pguidVendor,
  [in]  DWORD              dwMetadataOptions,
  [out] IWICMetadataWriter **ppIWriter
);