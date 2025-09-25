typedef struct _MPR_SERVER_2 {
  DWORD dwNumPptpPorts;
  DWORD dwPptpPortFlags;
  DWORD dwNumL2tpPorts;
  DWORD dwL2tpPortFlags;
  DWORD dwNumSstpPorts;
  DWORD dwSstpPortFlags;
} MPR_SERVER_2, *PMPR_SERVER_2;