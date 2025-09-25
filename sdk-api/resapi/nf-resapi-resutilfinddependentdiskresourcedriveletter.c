DWORD ResUtilFindDependentDiskResourceDriveLetter(
  [in]      HCLUSTER  hCluster,
  [in]      HRESOURCE hResource,
  [out]     LPWSTR    pszDriveLetter,
  [in, out] DWORD     *pcchDriveLetter
);