typedef struct _CRYPTNET_URL_CACHE_RESPONSE_INFO {
  DWORD    cbSize;
  WORD     wResponseType;
  WORD     wResponseFlags;
  FILETIME LastModifiedTime;
  DWORD    dwMaxAge;
  LPCWSTR  pwszETag;
  DWORD    dwProxyId;
} CRYPTNET_URL_CACHE_RESPONSE_INFO, *PCRYPTNET_URL_CACHE_RESPONSE_INFO;