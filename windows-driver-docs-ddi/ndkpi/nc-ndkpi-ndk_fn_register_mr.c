NDK_FN_REGISTER_MR NdkFnRegisterMr;

NTSTATUS NdkFnRegisterMr(
  [in]           NDK_MR *pNdkMr,
  [in]           MDL *Mdl,
  [in]           SIZE_T Length,
  [in]           ULONG Flags,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}