NDK_FN_DEREGISTER_MR NdkFnDeregisterMr;

NTSTATUS NdkFnDeregisterMr(
  [in]           NDK_MR *pNdkMr,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}