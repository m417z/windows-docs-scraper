NDK_FN_SEND NdkFnSend;

NTSTATUS NdkFnSend(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge,
  [in]           ULONG Flags
)
{...}