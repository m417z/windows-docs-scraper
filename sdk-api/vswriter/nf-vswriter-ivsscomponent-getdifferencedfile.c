HRESULT GetDifferencedFile(
  [in]  UINT     iDifferencedFile,
  [out] BSTR     *pbstrPath,
  [out] BSTR     *pbstrFilespec,
  [out] BOOL     *pbRecursive,
  [out] BSTR     *pbstrLsnString,
  [out] FILETIME *pftLastModifyTime
);