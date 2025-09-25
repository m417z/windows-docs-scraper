HRESULT GetFileProperty(
  [in]  BSTR                       filePath,
  [in]  BSTR                       propertyName,
  [in]  FsrmGetFilePropertyOptions options,
  [out] IFsrmProperty              **property
);