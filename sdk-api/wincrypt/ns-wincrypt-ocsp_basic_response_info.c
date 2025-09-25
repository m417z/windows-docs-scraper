typedef struct _OCSP_BASIC_RESPONSE_INFO {
  DWORD                      dwVersion;
  DWORD                      dwResponderIdChoice;
  union {
    CERT_NAME_BLOB  ByNameResponderId;
    CRYPT_HASH_BLOB ByKeyResponderId;
  } DUMMYUNIONNAME;
  FILETIME                   ProducedAt;
  DWORD                      cResponseEntry;
  POCSP_BASIC_RESPONSE_ENTRY rgResponseEntry;
  DWORD                      cExtension;
  PCERT_EXTENSION            rgExtension;
} OCSP_BASIC_RESPONSE_INFO, *POCSP_BASIC_RESPONSE_INFO;