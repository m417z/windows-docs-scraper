typedef struct drt_bootstrap_provider_tag {
  PVOID    pvContext;
  HRESULT( )(const PVOID pvContext) *Attach;
  VOID( )(const PVOID pvContext)    *Detach;
  HRESULT((const PVOID pvContext,BOOL fSplitDetect,ULONG timeout,ULONG cMaxResults,DRT_BOOTSTRAP_RESOLVE_CONTEXT *ResolveContext,BOOL *fFatalError) * )InitResolve;
  HRESULT()(const PVOID pvContext, const PVOID pvCallbackContext,DRT_BOOTSTRAP_RESOLVE_CALLBACK callback,DRT_BOOTSTRAP_RESOLVE_CONTEXT ResolveContext,BOOL *fFatalError) * IssueResolve;
  VOID( )(const PVOID pvContext,DRT_BOOTSTRAP_RESOLVE_CONTEXT ResolveContext)    *EndResolve;
  HRESULT()(const PVOID pvContext, const SOCKET_ADDRESS_LIST *pAddressList) * Register;
  VOID( )(const PVOID pvContext)    *Unregister;
} DRT_BOOTSTRAP_PROVIDER, *PDRT_BOOTSTRAP_PROVIDER;