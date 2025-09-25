typedef struct _CERT_REQUEST_INFO {
  DWORD                dwVersion;
  CERT_NAME_BLOB       Subject;
  CERT_PUBLIC_KEY_INFO SubjectPublicKeyInfo;
  DWORD                cAttribute;
  PCRYPT_ATTRIBUTE     rgAttribute;
} CERT_REQUEST_INFO, *PCERT_REQUEST_INFO;