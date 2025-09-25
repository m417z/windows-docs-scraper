typedef struct _NETSETUP_PROVISIONING_PARAMS {
  DWORD   dwVersion;
  LPCWSTR lpDomain;
  LPCWSTR lpHostName;
  LPCWSTR lpMachineAccountOU;
  LPCWSTR lpDcName;
  DWORD   dwProvisionOptions;
  LPCWSTR *aCertTemplateNames;
  DWORD   cCertTemplateNames;
  LPCWSTR *aMachinePolicyNames;
  DWORD   cMachinePolicyNames;
  LPCWSTR *aMachinePolicyPaths;
  DWORD   cMachinePolicyPaths;
  LPWSTR  lpNetbiosName;
  LPWSTR  lpSiteName;
  LPWSTR  lpPrimaryDNSDomain;
} NETSETUP_PROVISIONING_PARAMS, *PNETSETUP_PROVISIONING_PARAMS;