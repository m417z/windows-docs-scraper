typedef struct _EapCertificateCredential {
  BYTE   certHash[CERTIFICATE_HASH_LENGTH];
  LPWSTR password;
} EapCertificateCredential;