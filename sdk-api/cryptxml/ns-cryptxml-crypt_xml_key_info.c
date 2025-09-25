typedef struct _CRYPT_XML_KEY_INFO {
  ULONG                   cbSize;
  LPCWSTR                 wszId;
  UINT                    cKeyInfo;
  CRYPT_XML_KEY_INFO_ITEM *rgKeyInfo;
  BCRYPT_KEY_HANDLE       hVerifyKey;
} CRYPT_XML_KEY_INFO, *PCRYPT_XML_KEY_INFO;