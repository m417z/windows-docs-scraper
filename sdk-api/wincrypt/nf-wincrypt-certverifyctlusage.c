BOOL CertVerifyCTLUsage(
  [in]           DWORD                    dwEncodingType,
  [in]           DWORD                    dwSubjectType,
  [in]           void                     *pvSubject,
  [in]           PCTL_USAGE               pSubjectUsage,
  [in]           DWORD                    dwFlags,
  [in, optional] PCTL_VERIFY_USAGE_PARA   pVerifyUsagePara,
  [in, out]      PCTL_VERIFY_USAGE_STATUS pVerifyUsageStatus
);