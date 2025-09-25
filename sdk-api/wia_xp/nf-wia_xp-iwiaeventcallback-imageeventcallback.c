HRESULT ImageEventCallback(
  [in]      const GUID *pEventGUID,
  [in]      BSTR       bstrEventDescription,
  [in]      BSTR       bstrDeviceID,
  [in]      BSTR       bstrDeviceDescription,
  [in]      DWORD      dwDeviceType,
  [in]      BSTR       bstrFullItemName,
  [in, out] ULONG      *pulEventType,
  [in]      ULONG      ulReserved
);