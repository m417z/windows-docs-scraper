typedef struct {
  DWORD      dsSize;
  DWORD      dwCount;
  DOMAINDESC aDomains[1];
} DOMAIN_TREE, DOMAINTREE, *PDOMAIN_TREE, *LPDOMAINTREE;