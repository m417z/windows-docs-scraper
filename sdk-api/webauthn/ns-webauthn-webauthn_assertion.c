typedef struct _WEBAUTHN_ASSERTION {
  DWORD                      dwVersion;
  DWORD                      cbAuthenticatorData;
  PBYTE                      pbAuthenticatorData;
  DWORD                      cbSignature;
  PBYTE                      pbSignature;
  WEBAUTHN_CREDENTIAL        Credential;
  DWORD                      cbUserId;
  PBYTE                      pbUserId;
  WEBAUTHN_EXTENSIONS        Extensions;
  DWORD                      cbCredLargeBlob;
  PBYTE                      pbCredLargeBlob;
  DWORD                      dwCredLargeBlobStatus;
  PWEBAUTHN_HMAC_SECRET_SALT pHmacSecret;
  DWORD                      dwUsedTransport;
  DWORD                      cbUnsignedExtensionOutputs;
  PBYTE                      pbUnsignedExtensionOutputs;
} WEBAUTHN_ASSERTION, *PWEBAUTHN_ASSERTION;