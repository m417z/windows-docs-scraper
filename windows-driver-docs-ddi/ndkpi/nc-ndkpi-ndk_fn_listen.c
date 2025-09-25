NDK_FN_LISTEN NdkFnListen;

NTSTATUS NdkFnListen(
  [in]           NDK_LISTENER *pNdkListener,
                 const PSOCKADDR pAddress,
  [in]           ULONG AddressLength,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}