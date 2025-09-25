HRESULT CreateMediaKeys2(
  [in]           BSTR         keySystem,
  [in]           BSTR         defaultCdmStorePath,
  [in, optional] BSTR         inprivateCdmStorePath,
  [out]          IMFMediaKeys **ppKeys
);