typedef struct _DNS_SVCB_DATA {
  WORD           wSvcPriority;
  PSTR           pszTargetName;
  WORD           cSvcParams;
  DNS_SVCB_PARAM *pSvcParams;
} DNS_SVCB_DATA;