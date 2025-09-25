USERENVAPI DWORD GetAppliedGPOListA(
  [in]  DWORD                 dwFlags,
  [in]  LPCSTR                pMachineName,
  [in]  PSID                  pSidUser,
  [in]  GUID                  *pGuidExtension,
  [out] PGROUP_POLICY_OBJECTA *ppGPOList
);