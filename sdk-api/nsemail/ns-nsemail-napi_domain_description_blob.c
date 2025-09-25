typedef struct napi_domain_description_blob_tag {
  DWORD AuthLevel;
  DWORD cchDomainName;
  DWORD OffsetNextDomainDescription;
  DWORD OffsetThisDomainName;
} NAPI_DOMAIN_DESCRIPTION_BLOB;