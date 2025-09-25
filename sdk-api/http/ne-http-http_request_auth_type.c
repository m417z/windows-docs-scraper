typedef enum _HTTP_REQUEST_AUTH_TYPE {
  HttpRequestAuthTypeNone = 0,
  HttpRequestAuthTypeBasic,
  HttpRequestAuthTypeDigest,
  HttpRequestAuthTypeNTLM,
  HttpRequestAuthTypeNegotiate,
  HttpRequestAuthTypeKerberos
} HTTP_REQUEST_AUTH_TYPE, *PHTTP_REQUEST_AUTH_TYPE;