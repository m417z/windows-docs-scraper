UINT MsiGetFeatureUsageW(
  [in]  LPCWSTR szProduct,
  [in]  LPCWSTR szFeature,
  [out] LPDWORD pdwUseCount,
  [out] LPWORD  pwDateUsed
);