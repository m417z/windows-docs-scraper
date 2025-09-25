HRESULT RegisterDevice(
  [in]  BSTR bstrXMLDesc,
  [in]  BSTR bstrProgIDDeviceControlClass,
  [in]  BSTR bstrInitString,
  [in]  BSTR bstrContainerId,
  [in]  BSTR bstrResourcePath,
  [in]  long nLifeTime,
  [out] BSTR *pbstrDeviceIdentifier
);