HRESULT RegisterEventCallbackInterface(
  [in]  LONG              lFlags,
  [in]  BSTR              bstrDeviceID,
  [in]  const GUID        *pEventGUID,
  [in]  IWiaEventCallback *pIWiaEventCallback,
  [out] IUnknown          **pEventObject
);