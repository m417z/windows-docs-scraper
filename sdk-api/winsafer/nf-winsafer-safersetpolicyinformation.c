BOOL SaferSetPolicyInformation(
  [in] DWORD                   dwScopeId,
  [in] SAFER_POLICY_INFO_CLASS SaferPolicyInfoClass,
  [in] DWORD                   InfoBufferSize,
  [in] PVOID                   InfoBuffer,
       LPVOID                  lpReserved
);