typedef struct peer_group_properties_tag {
  DWORD        dwSize;
  DWORD        dwFlags;
  PWSTR        pwzCloud;
  PWSTR        pwzClassifier;
  PWSTR        pwzGroupPeerName;
  PWSTR        pwzCreatorPeerName;
  PWSTR        pwzFriendlyName;
  PWSTR        pwzComment;
  ULONG        ulMemberDataLifetime;
  ULONG        ulPresenceLifetime;
  DWORD        dwAuthenticationSchemes;
  PWSTR        pwzGroupPassword;
  PEER_ROLE_ID groupPasswordRole;
} PEER_GROUP_PROPERTIES, *PPEER_GROUP_PROPERTIES;