USERENVAPI DWORD GetAppliedGPOListW(
  [in]  DWORD                 dwFlags,
  [in]  LPCWSTR               pMachineName,
  [in]  PSID                  pSidUser,
  [in]  GUID                  *pGuidExtension,
  [out] PGROUP_POLICY_OBJECTW *ppGPOList
);