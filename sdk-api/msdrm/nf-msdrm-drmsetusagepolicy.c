DRMEXPORT HRESULT UDAPICALL DRMSetUsagePolicy(
  [in] DRMPUBHANDLE         hIssuanceLicense,
  [in] DRM_USAGEPOLICY_TYPE eUsagePolicyType,
  [in] BOOL                 fDelete,
  [in] BOOL                 fExclusion,
  [in] PWSTR                wszName,
  [in] PWSTR                wszMinVersion,
  [in] PWSTR                wszMaxVersion,
  [in] PWSTR                wszPublicKey,
  [in] PWSTR                wszDigestAlgorithm,
  [in] BYTE                 *pbDigest,
  [in] UINT                 cbDigest
);