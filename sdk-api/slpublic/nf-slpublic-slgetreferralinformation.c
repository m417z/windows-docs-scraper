HRESULT SLGetReferralInformation(
  [in]  HSLC           hSLC,
  [in]  SLREFERRALTYPE eReferralType,
  [in]  const SLID     *pSkuOrAppId,
  [in]  PCWSTR         pwszValueName,
  [out] PWSTR          *ppwszValue
);