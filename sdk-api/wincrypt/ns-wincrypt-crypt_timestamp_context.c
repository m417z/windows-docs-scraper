typedef struct _CRYPT_TIMESTAMP_CONTEXT {
  DWORD                 cbEncoded;
  BYTE                  *pbEncoded;
  PCRYPT_TIMESTAMP_INFO pTimeStamp;
} CRYPT_TIMESTAMP_CONTEXT, *PCRYPT_TIMESTAMP_CONTEXT;