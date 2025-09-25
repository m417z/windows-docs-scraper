HRESULT AVISaveVA(
  LPCSTR               szFile,
  CLSID                *pclsidHandler,
  AVISAVECALLBACK      lpfnCallback,
  int                  nStreams,
  PAVISTREAM           *ppavi,
  LPAVICOMPRESSOPTIONS *plpOptions
);