typedef struct _CERT_CHAIN_ENGINE_CONFIG {
  DWORD      cbSize;
  HCERTSTORE hRestrictedRoot;
  HCERTSTORE hRestrictedTrust;
  HCERTSTORE hRestrictedOther;
  DWORD      cAdditionalStore;
  HCERTSTORE *rghAdditionalStore;
  DWORD      dwFlags;
  DWORD      dwUrlRetrievalTimeout;
  DWORD      MaximumCachedCertificates;
  DWORD      CycleDetectionModulus;
  HCERTSTORE hExclusiveRoot;
  HCERTSTORE hExclusiveTrustedPeople;
  DWORD      dwExclusiveFlags;
} CERT_CHAIN_ENGINE_CONFIG, *PCERT_CHAIN_ENGINE_CONFIG;