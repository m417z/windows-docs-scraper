typedef struct _WEBAUTHN_CREDENTIAL {
  DWORD  dwVersion;
  DWORD  cbId;
  PBYTE  pbId;
  PCWSTR pwszCredentialType;
} WEBAUTHN_CREDENTIAL, *PWEBAUTHN_CREDENTIAL;