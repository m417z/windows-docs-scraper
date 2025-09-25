typedef struct _CERT_KEYGEN_REQUEST_INFO {
  DWORD                dwVersion;
  CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
  LPWSTR               pwszChallengeString;
} CERT_KEYGEN_REQUEST_INFO, *PCERT_KEYGEN_REQUEST_INFO;