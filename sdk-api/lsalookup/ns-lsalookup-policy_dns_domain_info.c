typedef struct _POLICY_DNS_DOMAIN_INFO {
  LSA_UNICODE_STRING Name;
  LSA_UNICODE_STRING DnsDomainName;
  LSA_UNICODE_STRING DnsForestName;
  GUID               DomainGuid;
  PSID               Sid;
} POLICY_DNS_DOMAIN_INFO, *PPOLICY_DNS_DOMAIN_INFO;