BOOL EcGetSubscriptionRunTimeStatus(
  [in]  LPCWSTR                                SubscriptionName,
  [in]  EC_SUBSCRIPTION_RUNTIME_STATUS_INFO_ID StatusInfoId,
  [in]  LPCWSTR                                EventSourceName,
  [in]  DWORD                                  Flags,
  [in]  DWORD                                  StatusValueBufferSize,
  [in]  PEC_VARIANT                            StatusValueBuffer,
  [out] PDWORD                                 StatusValueBufferUsed
);