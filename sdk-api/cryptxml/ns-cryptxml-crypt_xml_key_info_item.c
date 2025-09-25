typedef struct _CRYPT_XML_KEY_INFO_ITEM {
  DWORD dwType;
  union {
    LPCWSTR             wszKeyName;
    CRYPT_XML_KEY_VALUE KeyValue;
    CRYPT_XML_BLOB      RetrievalMethod;
    CRYPT_XML_X509DATA  X509Data;
    CRYPT_XML_BLOB      Custom;
  };
} CRYPT_XML_KEY_INFO_ITEM;