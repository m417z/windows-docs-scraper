HRESULT RestoreFiles(
  [in]  ULONG                  NumberOfFiles,
  [in]  BSTR                   *FileFullPaths,
  [in]  IDedupReadFileCallback *Store,
  [in]  DWORD                  Flags,
  [out] HRESULT                *FileResults
);