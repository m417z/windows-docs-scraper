typedef struct _CRYPT_XML_ALGORITHM {
  ULONG          cbSize;
  LPCWSTR        wszAlgorithm;
  CRYPT_XML_BLOB Encoded;
} CRYPT_XML_ALGORITHM, *PCRYPT_XML_ALGORITHM;