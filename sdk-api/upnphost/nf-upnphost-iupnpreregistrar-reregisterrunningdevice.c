HRESULT ReregisterRunningDevice(
  [in] BSTR     bstrDeviceIdentifier,
  [in] BSTR     bstrXMLDesc,
  [in] IUnknown *punkDeviceControl,
  [in] BSTR     bstrInitString,
  [in] BSTR     bstrResourcePath,
  [in] long     nLifeTime
);