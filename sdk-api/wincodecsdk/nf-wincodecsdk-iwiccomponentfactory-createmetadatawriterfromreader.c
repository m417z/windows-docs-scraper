HRESULT CreateMetadataWriterFromReader(
  [in]  IWICMetadataReader *pIReader,
  [in]  const GUID         *pguidVendor,
  [out] IWICMetadataWriter **ppIWriter
);