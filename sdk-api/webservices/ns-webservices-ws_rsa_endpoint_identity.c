typedef struct _WS_RSA_ENDPOINT_IDENTITY {
  WS_ENDPOINT_IDENTITY identity;
  WS_BYTES             modulus;
  WS_BYTES             exponent;
} WS_RSA_ENDPOINT_IDENTITY;