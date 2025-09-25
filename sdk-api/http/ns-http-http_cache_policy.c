typedef struct _HTTP_CACHE_POLICY {
  HTTP_CACHE_POLICY_TYPE Policy;
  ULONG                  SecondsToLive;
} HTTP_CACHE_POLICY, *PHTTP_CACHE_POLICY;