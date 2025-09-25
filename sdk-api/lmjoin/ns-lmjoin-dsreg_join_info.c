typedef struct _DSREG_JOIN_INFO {
  DSREG_JOIN_TYPE joinType;
  PCCERT_CONTEXT  pJoinCertificate;
  LPWSTR          pszDeviceId;
  LPWSTR          pszIdpDomain;
  LPWSTR          pszTenantId;
  LPWSTR          pszJoinUserEmail;
  LPWSTR          pszTenantDisplayName;
  LPWSTR          pszMdmEnrollmentUrl;
  LPWSTR          pszMdmTermsOfUseUrl;
  LPWSTR          pszMdmComplianceUrl;
  LPWSTR          pszUserSettingSyncUrl;
  DSREG_USER_INFO *pUserInfo;
} DSREG_JOIN_INFO, *PDSREG_JOIN_INFO;