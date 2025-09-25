typedef struct _WEBAUTHN_CREDENTIAL_DETAILS {
  DWORD                             dwVersion;
  DWORD                             cbCredentialID;
  PBYTE                             pbCredentialID;
  PWEBAUTHN_RP_ENTITY_INFORMATION   pRpInformation;
  PWEBAUTHN_USER_ENTITY_INFORMATION pUserInformation;
  BOOL                              bRemovable;
  BOOL                              bBackedUp;
} WEBAUTHN_CREDENTIAL_DETAILS, *PWEBAUTHN_CREDENTIAL_DETAILS;