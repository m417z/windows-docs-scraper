HRESULT OnDeviceStatusChange(
  IFaxServer2  *pFaxServer,
  long         lDeviceId,
  VARIANT_BOOL bPoweredOff,
  VARIANT_BOOL bSending,
  VARIANT_BOOL bReceiving,
  VARIANT_BOOL bRinging
);