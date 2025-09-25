typedef struct peer_member_tag {
  DWORD                dwSize;
  DWORD                dwFlags;
  PWSTR                pwzIdentity;
  PWSTR                pwzAttributes;
  ULONGLONG            ullNodeId;
  ULONG                cAddresses;
  PEER_ADDRESS         *pAddresses;
  PEER_CREDENTIAL_INFO *pCredentialInfo;
} PEER_MEMBER, *PPEER_MEMBER;