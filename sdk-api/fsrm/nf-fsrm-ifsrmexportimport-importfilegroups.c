HRESULT ImportFileGroups(
  [in]  BSTR                       filePath,
  [in]  VARIANT                    *fileGroupNamesSafeArray,
  [in]  BSTR                       remoteHost,
  [out] IFsrmCommittableCollection **fileGroups
);