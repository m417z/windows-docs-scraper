typedef struct _HTTP_SERVER_AUTHENTICATION_INFO {
  HTTP_PROPERTY_FLAGS                      Flags;
  ULONG                                    AuthSchemes;
  BOOLEAN                                  ReceiveMutualAuth;
  BOOLEAN                                  ReceiveContextHandle;
  BOOLEAN                                  DisableNTLMCredentialCaching;
  UCHAR                                    ExFlags;
  HTTP_SERVER_AUTHENTICATION_DIGEST_PARAMS DigestParams;
  HTTP_SERVER_AUTHENTICATION_BASIC_PARAMS  BasicParams;
} HTTP_SERVER_AUTHENTICATION_INFO, *PHTTP_SERVER_AUTHENTICATION_INFO;