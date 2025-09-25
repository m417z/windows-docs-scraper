typedef enum _HTTP_CACHE_POLICY_TYPE {
  HttpCachePolicyNocache,
  HttpCachePolicyUserInvalidates,
  HttpCachePolicyTimeToLive,
  HttpCachePolicyMaximum
} HTTP_CACHE_POLICY_TYPE, *PHTTP_CACHE_POLICY_TYPE;