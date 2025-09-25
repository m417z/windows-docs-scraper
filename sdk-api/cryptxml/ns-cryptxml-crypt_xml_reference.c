typedef struct _CRYPT_XML_REFERENCE {
  ULONG               cbSize;
  HCRYPTXML           hReference;
  LPCWSTR             wszId;
  LPCWSTR             wszUri;
  LPCWSTR             wszType;
  CRYPT_XML_ALGORITHM DigestMethod;
  CRYPT_DATA_BLOB     DigestValue;
  ULONG               cTransform;
  CRYPT_XML_ALGORITHM *rgTransform;
} CRYPT_XML_REFERENCE, *PCRYPT_XML_REFERENCE;