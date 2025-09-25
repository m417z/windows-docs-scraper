typedef struct _LSA_FOREST_TRUST_DOMAIN_INFO {
#if ...
  PISID              Sid;
#else
  PSID               Sid;
#endif
  LSA_UNICODE_STRING DnsName;
  LSA_UNICODE_STRING NetbiosName;
} LSA_FOREST_TRUST_DOMAIN_INFO, *PLSA_FOREST_TRUST_DOMAIN_INFO;