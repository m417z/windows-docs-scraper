HRESULT CreateBundleReaderFromSourceUri(
  [in]           LPCWSTR           uri,
  [in, optional] LPCWSTR           expectedDigest,
  [out]          IAppxBundleReader **bundleReader
);