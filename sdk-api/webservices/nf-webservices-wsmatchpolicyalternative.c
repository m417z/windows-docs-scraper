HRESULT WsMatchPolicyAlternative(
  [in]           WS_POLICY             *policy,
  [in]           ULONG                 alternativeIndex,
  [in]           WS_POLICY_CONSTRAINTS *policyConstraints,
  [in]           BOOL                  matchRequired,
  [in]           WS_HEAP               *heap,
  [in, optional] WS_ERROR              *error
);