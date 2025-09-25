BOOL SaferGetPolicyInformation(
  [in]  DWORD                   dwScopeId,
  [in]  SAFER_POLICY_INFO_CLASS SaferPolicyInfoClass,
  [in]  DWORD                   InfoBufferSize,
  [out] PVOID                   InfoBuffer,
  [out] PDWORD                  InfoBufferRetSize,
        LPVOID                  lpReserved
);