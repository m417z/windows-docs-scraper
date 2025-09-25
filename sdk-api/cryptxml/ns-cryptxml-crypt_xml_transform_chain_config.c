typedef struct _CRYPT_XML_TRANSFORM_CHAIN_CONFIG {
  ULONG                     cbSize;
  ULONG                     cTransformInfo;
  PCRYPT_XML_TRANSFORM_INFO *rgpTransformInfo;
} CRYPT_XML_TRANSFORM_CHAIN_CONFIG, *PCRYPT_XML_TRANSFORM_CHAIN_CONFIG;