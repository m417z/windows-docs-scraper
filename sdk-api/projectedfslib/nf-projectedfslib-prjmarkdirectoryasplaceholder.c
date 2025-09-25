HRESULT PrjMarkDirectoryAsPlaceholder(
  [in]           PCWSTR                             rootPathName,
  [in, optional] PCWSTR                             targetPathName,
  [in, optional] const PRJ_PLACEHOLDER_VERSION_INFO *versionInfo,
  [in]           const GUID                         *virtualizationInstanceID
);