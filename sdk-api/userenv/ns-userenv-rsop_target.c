typedef struct _RSOP_TARGET {
  WCHAR                *pwszAccountName;
  WCHAR                *pwszNewSOM;
  SAFEARRAY            *psaSecurityGroups;
  PRSOPTOKEN           pRsopToken;
  PGROUP_POLICY_OBJECT pGPOList;
  IWbemServices        *pWbemServices;
} RSOP_TARGET, *PRSOP_TARGET;