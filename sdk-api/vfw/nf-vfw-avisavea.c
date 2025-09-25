HRESULT AVISaveA(
  LPCSTR               szFile,
  CLSID                *pclsidHandler,
  AVISAVECALLBACK      lpfnCallback,
  int                  nStreams,
  PAVISTREAM           pfile,
  LPAVICOMPRESSOPTIONS lpOptions,
  ...                  
);