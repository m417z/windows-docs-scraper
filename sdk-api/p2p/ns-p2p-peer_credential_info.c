typedef struct peer_credential_info_tag {
  DWORD                dwSize;
  DWORD                dwFlags;
  PWSTR                pwzFriendlyName;
  CERT_PUBLIC_KEY_INFO *pPublicKey;
  PWSTR                pwzIssuerPeerName;
  PWSTR                pwzIssuerFriendlyName;
  FILETIME             ftValidityStart;
  FILETIME             ftValidityEnd;
  ULONG                cRoles;
  PEER_ROLE_ID         *pRoles;
} PEER_CREDENTIAL_INFO, *PPEER_CREDENTIAL_INFO;