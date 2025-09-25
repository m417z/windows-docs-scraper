NOT_BUILD_WINDOWS_DEPRECATE HRESULT PeerGroupIssueCredentials(
  [in]  HGROUP               hGroup,
  [in]  PCWSTR               pwzSubjectIdentity,
  [in]  PEER_CREDENTIAL_INFO *pCredentialInfo,
  [in]  DWORD                dwFlags,
  [out] PWSTR                *ppwzInvitation
);