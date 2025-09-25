typedef struct _CERT_X942_DH_PARAMETERS {
  CRYPT_UINT_BLOB                 p;
  CRYPT_UINT_BLOB                 g;
  CRYPT_UINT_BLOB                 q;
  CRYPT_UINT_BLOB                 j;
  PCERT_X942_DH_VALIDATION_PARAMS pValidationParams;
} CERT_X942_DH_PARAMETERS, *PCERT_X942_DH_PARAMETERS;