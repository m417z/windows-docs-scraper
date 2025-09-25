NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGroupCreateInvitation(
  [in]  HGROUP     hGroup,
  [in]  PCWSTR     pwzIdentityInfo,
  [in]  FILETIME   *pftExpiration,
  [in]  ULONG      cRoles,
  [in]  const GUID *pRoles,
  [out] PWSTR      *ppwzInvitation
);