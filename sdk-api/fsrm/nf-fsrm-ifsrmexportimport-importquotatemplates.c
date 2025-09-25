HRESULT ImportQuotaTemplates(
  [in]  BSTR                       filePath,
  [in]  VARIANT                    *templateNamesSafeArray,
  [in]  BSTR                       remoteHost,
  [out] IFsrmCommittableCollection **templates
);