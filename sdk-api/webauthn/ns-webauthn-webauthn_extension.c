typedef struct _WEBAUTHN_EXTENSION {
  LPCWSTR pwszExtensionIdentifier;
  DWORD   cbExtension;
  PVOID   pvExtension;
} WEBAUTHN_EXTENSION, *PWEBAUTHN_EXTENSION;