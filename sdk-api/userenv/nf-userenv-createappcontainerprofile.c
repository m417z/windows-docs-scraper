USERENVAPI HRESULT CreateAppContainerProfile(
  [in]  PCWSTR              pszAppContainerName,
  [in]  PCWSTR              pszDisplayName,
  [in]  PCWSTR              pszDescription,
  [in]  PSID_AND_ATTRIBUTES pCapabilities,
  [in]  DWORD               dwCapabilityCount,
  [out] PSID                *ppSidAppContainerSid
);