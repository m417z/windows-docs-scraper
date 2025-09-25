BOOL EcGetSubscriptionProperty(
  [in]  EC_HANDLE                   Subscription,
  [in]  EC_SUBSCRIPTION_PROPERTY_ID PropertyId,
  [in]  DWORD                       Flags,
  [in]  DWORD                       PropertyValueBufferSize,
  [in]  PEC_VARIANT                 PropertyValueBuffer,
  [out] PDWORD                      PropertyValueBufferUsed
);