HRESULT GetRootAndLogicalPrefixPaths(
  [in]           VSS_PWSZ pwszFilePath,
  [out]          VSS_PWSZ *ppwszRootPath,
  [out]          VSS_PWSZ *ppwszLogicalPrefix,
  [in, optional] BOOL     bNormalizeFQDNforRootPath
);