typedef struct _CRYPT_XML_TRANSFORM_INFO {
  ULONG                          cbSize;
  LPCWSTR                        wszAlgorithm;
  ULONG                          cbBufferSize;
  DWORD                          dwFlags;
  PFN_CRYPT_XML_CREATE_TRANSFORM pfnCreateTransform;
} CRYPT_XML_TRANSFORM_INFO, *PCRYPT_XML_TRANSFORM_INFO;