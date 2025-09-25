HRESULT WsGetPolicyProperty(
  [in]           WS_POLICY             *policy,
  [in]           WS_POLICY_PROPERTY_ID id,
                 void                  *value,
  [in]           ULONG                 valueSize,
  [in, optional] WS_ERROR              *error
);