typedef struct _WEBAUTHN_CREDENTIAL_EX {
  DWORD   dwVersion;
  DWORD   cbId;
  PBYTE   pbId;
  LPCWSTR pwszCredentialType;
  DWORD   dwTransports;
} WEBAUTHN_CREDENTIAL_EX, *PWEBAUTHN_CREDENTIAL_EX;