USERENVAPI HRESULT DeriveRestrictedAppContainerSidFromAppContainerSidAndRestrictedName(
  [in]  PSID   psidAppContainerSid,
  [in]  PCWSTR pszRestrictedAppContainerName,
  [out] PSID   *ppsidRestrictedAppContainerSid
);