HRESULT CreatePackageReaderFromSourceUri(
  [in]           LPCWSTR            uri,
  [in, optional] LPCWSTR            expectedDigest,
  [out]          IAppxPackageReader **packageReader
);