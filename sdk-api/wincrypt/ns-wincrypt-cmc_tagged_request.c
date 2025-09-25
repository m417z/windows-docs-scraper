typedef struct _CMC_TAGGED_REQUEST {
  DWORD dwTaggedRequestChoice;
  union {
    PCMC_TAGGED_CERT_REQUEST pTaggedCertRequest;
  } DUMMYUNIONNAME;
} CMC_TAGGED_REQUEST, *PCMC_TAGGED_REQUEST;