typedef struct _NETLOGON_INFO_4 {
#if ...
  wchar_t *netlog4_trusted_dc_name;
#if ...
  wchar_t *netlog4_trusted_domain_name;
#else
  LPWSTR  netlog4_trusted_dc_name;
#endif
#else
  LPWSTR  netlog4_trusted_domain_name;
#endif
} NETLOGON_INFO_4, *PNETLOGON_INFO_4;