typedef struct D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE {
  D3D11_1DDI_AUTHENTICATED_CONFIGURE_INPUT         Parameters;
  D3D11_1DDI_AUTHENTICATED_PROCESS_IDENTIFIER_TYPE ProcessType;
  HANDLE                                           ProcessHandle;
  BOOL                                             AllowAccess;
} D3D11_1DDI_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE;