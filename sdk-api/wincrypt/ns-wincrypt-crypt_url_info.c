typedef struct _CRYPT_URL_INFO {
  DWORD cbSize;
  DWORD dwSyncDeltaTime;
  DWORD cGroup;
  DWORD *rgcGroupEntry;
} CRYPT_URL_INFO, *PCRYPT_URL_INFO;