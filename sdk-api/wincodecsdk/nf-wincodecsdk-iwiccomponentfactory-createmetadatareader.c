HRESULT CreateMetadataReader(
  [in]  REFGUID            guidMetadataFormat,
  [in]  const GUID         *pguidVendor,
  [in]  DWORD              dwOptions,
  [in]  IStream            *pIStream,
  [out] IWICMetadataReader **ppIReader
);