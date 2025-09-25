HRESULT RegisterRunningDevice(
  [in]  BSTR     bstrXMLDesc,
  [in]  IUnknown *punkDeviceControl,
  [in]  BSTR     bstrInitString,
  [in]  BSTR     bstrResourcePath,
  [in]  long     nLifeTime,
  [out] BSTR     *pbstrDeviceIdentifier
);