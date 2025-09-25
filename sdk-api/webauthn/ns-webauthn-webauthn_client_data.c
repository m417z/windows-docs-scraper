typedef struct _WEBAUTHN_CLIENT_DATA {
  DWORD   dwVersion;
  DWORD   cbClientDataJSON;
  PBYTE   pbClientDataJSON;
  LPCWSTR pwszHashAlgId;
} WEBAUTHN_CLIENT_DATA, *PWEBAUTHN_CLIENT_DATA;