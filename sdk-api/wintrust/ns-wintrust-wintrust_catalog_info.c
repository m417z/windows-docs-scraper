typedef struct WINTRUST_CATALOG_INFO_ {
  DWORD         cbStruct;
  DWORD         dwCatalogVersion;
  LPCWSTR       pcwszCatalogFilePath;
  LPCWSTR       pcwszMemberTag;
  LPCWSTR       pcwszMemberFilePath;
  HANDLE        hMemberFile;
  BYTE          *pbCalculatedFileHash;
  DWORD         cbCalculatedFileHash;
  PCCTL_CONTEXT pcCatalogContext;
  HCATADMIN     hCatAdmin;
} WINTRUST_CATALOG_INFO, *PWINTRUST_CATALOG_INFO;