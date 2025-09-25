typedef struct _CRYPT_XML_DATA_PROVIDER {
  void                              *pvCallbackState;
  ULONG                             cbBufferSize;
  PFN_CRYPT_XML_DATA_PROVIDER_READ  pfnRead;
  PFN_CRYPT_XML_DATA_PROVIDER_CLOSE pfnClose;
} CRYPT_XML_DATA_PROVIDER, *PCRYPT_XML_DATA_PROVIDER;