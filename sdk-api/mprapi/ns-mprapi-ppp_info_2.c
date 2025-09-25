typedef struct _PPP_INFO_2 {
  PPP_NBFCP_INFO nbf;
  PPP_IPCP_INFO2 ip;
  PPP_IPXCP_INFO ipx;
  PPP_ATCP_INFO  at;
  PPP_CCP_INFO   ccp;
  PPP_LCP_INFO   lcp;
} PPP_INFO_2;