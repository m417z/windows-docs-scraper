HRESULT OnQueryCommandComplete(
  [in] IMbnDeviceService *deviceService,
  [in] ULONG             responseID,
  [in] SAFEARRAY         *deviceServiceData,
  [in] HRESULT           status,
  [in] ULONG             requestID
);