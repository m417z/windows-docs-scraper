typedef struct _CRYPT_TIMESTAMP_RESPONSE {
  DWORD          dwStatus;
  DWORD          cFreeText;
  LPWSTR         *rgFreeText;
  CRYPT_BIT_BLOB FailureInfo;
  CRYPT_DER_BLOB ContentInfo;
} CRYPT_TIMESTAMP_RESPONSE, *PCRYPT_TIMESTAMP_RESPONSE;