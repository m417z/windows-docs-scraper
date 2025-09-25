HRESULT RoResolveNamespace(
  [in, optional]  const HSTRING name,
  [in, optional]  const HSTRING windowsMetaDataDir,
  [in]            const DWORD   packageGraphDirsCount,
  [in, optional]  const HSTRING *packageGraphDirs,
  [out, optional] DWORD         *metaDataFilePathsCount,
  [out, optional] HSTRING       **metaDataFilePaths,
  [out, optional] DWORD         *subNamespacesCount,
  [out, optional] HSTRING       **subNamespaces
);