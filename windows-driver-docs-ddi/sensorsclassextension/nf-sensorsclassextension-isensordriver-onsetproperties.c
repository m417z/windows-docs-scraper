HRESULT OnSetProperties(
  [in]  IWDFFile              *pClientFile,
  [in]  LPWSTR                pwszSensorID,
  [in]  IPortableDeviceValues *pPropertiesToSet,
  [out] IPortableDeviceValues **ppResults
);