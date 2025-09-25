typedef struct {
  PWSTR pNamePrimaryServer;
  PWSTR pNameAdministrator;
  DWORD dwSerialNo;
  DWORD dwRefresh;
  DWORD dwRetry;
  DWORD dwExpire;
  DWORD dwDefaultTtl;
} DNS_SOA_DATAW, *PDNS_SOA_DATAW;