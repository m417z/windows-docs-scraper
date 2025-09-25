typedef struct _CRYPT_PROPERTY_REF {
  PWSTR  pszProperty;
  ULONG  cbValue;
  PUCHAR pbValue;
} CRYPT_PROPERTY_REF, *PCRYPT_PROPERTY_REF;