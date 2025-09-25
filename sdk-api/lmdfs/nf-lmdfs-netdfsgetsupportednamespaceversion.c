NET_API_STATUS NET_API_FUNCTION NetDfsGetSupportedNamespaceVersion(
  [in]  DFS_NAMESPACE_VERSION_ORIGIN          Origin,
  [in]  PWSTR                                 pName,
  [out] PDFS_SUPPORTED_NAMESPACE_VERSION_INFO *ppVersionInfo
);