typedef struct _CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO {
  DWORD                       cbSize;
  int                         iDeltaCrlIndicator;
  LPFILETIME                  pftCacheResync;
  LPFILETIME                  pLastSyncTime;
  LPFILETIME                  pMaxAgeTime;
  PCERT_REVOCATION_CHAIN_PARA pChainPara;
  PCRYPT_INTEGER_BLOB         pDeltaCrlIndicator;
} CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO, *PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO;