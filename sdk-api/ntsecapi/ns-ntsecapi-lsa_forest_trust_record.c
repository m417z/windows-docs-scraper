typedef struct _LSA_FOREST_TRUST_RECORD {
  ULONG                        Flags;
  LSA_FOREST_TRUST_RECORD_TYPE ForestTrustType;
  LARGE_INTEGER                Time;
#if ...
  union {
    LSA_UNICODE_STRING           TopLevelName;
    LSA_FOREST_TRUST_DOMAIN_INFO DomainInfo;
    LSA_FOREST_TRUST_BINARY_DATA Data;
  } ForestTrustData;
#else
  union {
    LSA_UNICODE_STRING           TopLevelName;
    LSA_FOREST_TRUST_DOMAIN_INFO DomainInfo;
    LSA_FOREST_TRUST_BINARY_DATA Data;
  } ForestTrustData;
#endif
} LSA_FOREST_TRUST_RECORD, *PLSA_FOREST_TRUST_RECORD;