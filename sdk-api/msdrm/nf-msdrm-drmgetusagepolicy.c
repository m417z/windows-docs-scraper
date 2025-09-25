DRMEXPORT HRESULT UDAPICALL DRMGetUsagePolicy(
  [in]      DRMPUBHANDLE         hIssuanceLicense,
  [in]      UINT                 uIndex,
  [out]     DRM_USAGEPOLICY_TYPE *peUsagePolicyType,
  [out]     BOOL                 *pfExclusion,
  [in, out] UINT                 *puNameLength,
  [out]     PWSTR                wszName,
  [in, out] UINT                 *puMinVersionLength,
  [out]     PWSTR                wszMinVersion,
  [in, out] UINT                 *puMaxVersionLength,
  [out]     PWSTR                wszMaxVersion,
  [in, out] UINT                 *puPublicKeyLength,
  [out]     PWSTR                wszPublicKey,
  [in, out] UINT                 *puDigestAlgorithmLength,
  [out]     PWSTR                wszDigestAlgorithm,
  [in, out] UINT                 *pcbDigest,
  [out]     BYTE                 *pbDigest
);