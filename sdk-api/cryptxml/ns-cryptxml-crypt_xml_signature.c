typedef struct _CRYPT_XML_SIGNATURE {
  ULONG                 cbSize;
  HCRYPTXML             hSignature;
  LPCWSTR               wszId;
  CRYPT_XML_SIGNED_INFO SignedInfo;
  CRYPT_DATA_BLOB       SignatureValue;
  CRYPT_XML_KEY_INFO    *pKeyInfo;
  ULONG                 cObject;
  PCRYPT_XML_OBJECT     *rgpObject;
} CRYPT_XML_SIGNATURE, *PCRYPT_XML_SIGNATURE;