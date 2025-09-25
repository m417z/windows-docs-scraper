typedef enum _DNS_NAME_FORMAT {
  DnsNameDomain,
  DnsNameDomainLabel,
  DnsNameHostnameFull,
  DnsNameHostnameLabel,
  DnsNameWildcard,
  DnsNameSrvRecord,
  DnsNameValidateTld
} DNS_NAME_FORMAT;