HRESULT AVISaveW(
  LPCWSTR              szFile,
  CLSID                *pclsidHandler,
  AVISAVECALLBACK      lpfnCallback,
  int                  nStreams,
  PAVISTREAM           pfile,
  LPAVICOMPRESSOPTIONS lpOptions,
  ...                  
);