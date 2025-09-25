typedef struct {
  PSTR  pNamePrimaryServer;
  PSTR  pNameAdministrator;
  DWORD dwSerialNo;
  DWORD dwRefresh;
  DWORD dwRetry;
  DWORD dwExpire;
  DWORD dwDefaultTtl;
} DNS_SOA_DATAA, *PDNS_SOA_DATAA;