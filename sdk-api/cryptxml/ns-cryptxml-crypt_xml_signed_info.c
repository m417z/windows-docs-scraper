typedef struct _CRYPT_XML_SIGNED_INFO {
  ULONG                cbSize;
  LPCWSTR              wszId;
  CRYPT_XML_ALGORITHM  Canonicalization;
  CRYPT_XML_ALGORITHM  SignatureMethod;
  ULONG                cReference;
  PCRYPT_XML_REFERENCE *rgpReference;
  CRYPT_XML_BLOB       Encoded;
} CRYPT_XML_SIGNED_INFO, *PCRYPT_XML_SIGNED_INFO;