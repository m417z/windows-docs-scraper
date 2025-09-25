HRESULT CreateQueryWriterFromReader(
  [in]  IWICMetadataQueryReader *pIQueryReader,
  [in]  const GUID              *pguidVendor,
  [out] IWICMetadataQueryWriter **ppIQueryWriter
);