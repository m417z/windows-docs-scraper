HANDLE CreateResourceManager(
  [in, optional] LPSECURITY_ATTRIBUTES lpResourceManagerAttributes,
  [in]           LPGUID                ResourceManagerId,
  [in, optional] DWORD                 CreateOptions,
  [in]           HANDLE                TmHandle,
  [in, optional] LPWSTR                Description
);