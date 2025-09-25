HRESULT RegisterCallNotifications(
  [in]  ITAddress    *pAddress,
  [in]  VARIANT_BOOL fMonitor,
  [in]  VARIANT_BOOL fOwner,
  [in]  long         lMediaTypes,
  [in]  long         lCallbackInstance,
  [out] long         *plRegister
);