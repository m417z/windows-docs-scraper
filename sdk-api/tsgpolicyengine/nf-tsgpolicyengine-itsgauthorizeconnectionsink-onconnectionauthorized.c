HRESULT OnConnectionAuthorized(
  [in] HRESULT                     hrIn,
  [in] GUID                        mainSessionId,
  [in] ULONG                       cbSoHResponse,
  [in] BYTE                        *pbSoHResponse,
  [in] ULONG                       idleTimeout,
  [in] ULONG                       sessionTimeout,
  [in] SESSION_TIMEOUT_ACTION_TYPE sessionTimeoutAction,
  [in] AATrustClassID              trustClass,
  [in] PolicyAttributes            policyAttributes
);