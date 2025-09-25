NDK_FN_CREATE_SHARED_ENDPOINT NdkFnCreateSharedEndpoint;

NTSTATUS NdkFnCreateSharedEndpoint(
  [in]           NDK_ADAPTER *pNdkAdapter,
                 const PSOCKADDR pAddress,
  [in]           ULONG AddressLength,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_SHARED_ENDPOINT **ppNdkSharedEndpoint
)
{...}