typedef struct _CRYPT_XML_BLOB {
  CRYPT_XML_CHARSET dwCharset;
  ULONG             cbData;
  BYTE              *pbData;
} CRYPT_XML_BLOB, *PCRYPT_XML_BLOB;