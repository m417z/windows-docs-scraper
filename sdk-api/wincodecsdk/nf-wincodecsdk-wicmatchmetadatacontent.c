HRESULT WICMatchMetadataContent(
  [in]  REFGUID    guidContainerFormat,
  [in]  const GUID *pguidVendor,
  [in]  IStream    *pIStream,
  [out] GUID       *pguidMetadataFormat
);