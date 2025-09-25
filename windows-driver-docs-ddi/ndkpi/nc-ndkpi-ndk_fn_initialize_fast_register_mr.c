NDK_FN_INITIALIZE_FAST_REGISTER_MR NdkFnInitializeFastRegisterMr;

NTSTATUS NdkFnInitializeFastRegisterMr(
  [in]           NDK_MR *pNdkMr,
  [in]           ULONG AdapterPageCount,
  [in]           BOOLEAN RemoteAccess,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}