typedef struct _CRYPTNET_URL_CACHE_PRE_FETCH_INFO {
  DWORD    cbSize;
  DWORD    dwObjectType;
  DWORD    dwError;
  DWORD    dwReserved;
  FILETIME ThisUpdateTime;
  FILETIME NextUpdateTime;
  FILETIME PublishTime;
} CRYPTNET_URL_CACHE_PRE_FETCH_INFO, *PCRYPTNET_URL_CACHE_PRE_FETCH_INFO;