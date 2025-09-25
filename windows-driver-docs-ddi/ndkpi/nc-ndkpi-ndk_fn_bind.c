NDK_FN_BIND NdkFnBind;

NTSTATUS NdkFnBind(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
  [in]           NDK_MR *pMr,
  [in]           NDK_MW *pMw,
  [in]           PVOID VirtualAddress,
  [in]           SIZE_T Length,
  [in]           ULONG Flags
)
{...}