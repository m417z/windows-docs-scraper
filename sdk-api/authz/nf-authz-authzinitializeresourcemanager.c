AUTHZAPI BOOL AuthzInitializeResourceManager(
  [in]           DWORD                            Flags,
  [in, optional] PFN_AUTHZ_DYNAMIC_ACCESS_CHECK   pfnDynamicAccessCheck,
  [in, optional] PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS pfnComputeDynamicGroups,
  [in, optional] PFN_AUTHZ_FREE_DYNAMIC_GROUPS    pfnFreeDynamicGroups,
  [in]           PCWSTR                           szResourceManagerName,
  [out]          PAUTHZ_RESOURCE_MANAGER_HANDLE   phAuthzResourceManager
);