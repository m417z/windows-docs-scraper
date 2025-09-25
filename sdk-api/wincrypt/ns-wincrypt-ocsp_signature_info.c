typedef struct _OCSP_SIGNATURE_INFO {
  CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
  CRYPT_BIT_BLOB             Signature;
  DWORD                      cCertEncoded;
  PCERT_BLOB                 rgCertEncoded;
} OCSP_SIGNATURE_INFO, *POCSP_SIGNATURE_INFO;