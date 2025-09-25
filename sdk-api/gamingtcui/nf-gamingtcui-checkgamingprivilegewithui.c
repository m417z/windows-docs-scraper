HRESULT CheckGamingPrivilegeWithUI(
  [in]           UINT32                  privilegeId,
  [in]           HSTRING                 scope,
  [in]           HSTRING                 policy,
  [in, optional] HSTRING                 friendlyMessage,
  [in]           GameUICompletionRoutine completionRoutine,
  [in, optional] void                    *context
);