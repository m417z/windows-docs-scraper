typedef struct _AUTHZ_INIT_INFO {
  USHORT                               version;
  PCWSTR                               szResourceManagerName;
  PFN_AUTHZ_DYNAMIC_ACCESS_CHECK       pfnDynamicAccessCheck;
  PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS     pfnComputeDynamicGroups;
  PFN_AUTHZ_FREE_DYNAMIC_GROUPS        pfnFreeDynamicGroups;
  PFN_AUTHZ_GET_CENTRAL_ACCESS_POLICY  pfnGetCentralAccessPolicy;
  PFN_AUTHZ_FREE_CENTRAL_ACCESS_POLICY pfnFreeCentralAccessPolicy;
} AUTHZ_INIT_INFO, *PAUTHZ_INIT_INFO;