HRESULT CreateMetadataReaderFromContainer(
  [in]  REFGUID            guidContainerFormat,
  [in]  const GUID         *pguidVendor,
  [in]  DWORD              dwOptions,
  [in]  IStream            *pIStream,
  [out] IWICMetadataReader **ppIReader
);