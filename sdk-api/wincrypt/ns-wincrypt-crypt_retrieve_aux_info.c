typedef struct _CRYPT_RETRIEVE_AUX_INFO {
  DWORD                              cbSize;
  FILETIME                           *pLastSyncTime;
  DWORD                              dwMaxUrlRetrievalByteCount;
  PCRYPTNET_URL_CACHE_PRE_FETCH_INFO pPreFetchInfo;
  PCRYPTNET_URL_CACHE_FLUSH_INFO     pFlushInfo;
  PCRYPTNET_URL_CACHE_RESPONSE_INFO  *ppResponseInfo;
  LPWSTR                             pwszCacheFileNamePrefix;
  LPFILETIME                         pftCacheResync;
  BOOL                               fProxyCacheRetrieval;
  DWORD                              dwHttpStatusCode;
  LPWSTR                             *ppwszErrorResponseHeaders;
  PCRYPT_DATA_BLOB                   *ppErrorContentBlob;
} CRYPT_RETRIEVE_AUX_INFO, *PCRYPT_RETRIEVE_AUX_INFO;