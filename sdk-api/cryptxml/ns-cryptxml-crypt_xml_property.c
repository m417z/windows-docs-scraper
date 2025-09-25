typedef struct _CRYPT_XML_PROPERTY {
  CRYPT_XML_PROPERTY_ID dwPropId;
  const void            *pvValue;
  ULONG                 cbValue;
} CRYPT_XML_PROPERTY, *PCRYPT_XML_PROPERTY;