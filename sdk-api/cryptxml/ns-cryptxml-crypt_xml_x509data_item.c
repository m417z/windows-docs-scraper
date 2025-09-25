typedef struct _CRYPT_XML_X509DATA_ITEM {
  DWORD dwType;
  union {
    CRYPT_XML_ISSUER_SERIAL IssuerSerial;
    CRYPT_XML_DATA_BLOB     SKI;
    LPCWSTR                 wszSubjectName;
    CRYPT_XML_DATA_BLOB     Certificate;
    CRYPT_XML_DATA_BLOB     CRL;
    CRYPT_XML_BLOB          Custom;
  };
} CRYPT_XML_X509DATA_ITEM;