typedef struct napi_provider_installation_blob_tag {
  DWORD dwVersion;
  DWORD dwProviderType;
  DWORD fSupportsWildCard;
  ULONG cDomains;
  ULONG OffsetFirstDomain;
} NAPI_PROVIDER_INSTALLATION_BLOB;