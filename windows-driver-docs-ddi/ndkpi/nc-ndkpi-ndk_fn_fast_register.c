NDK_FN_FAST_REGISTER NdkFnFastRegister;

NTSTATUS NdkFnFastRegister(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
  [in]           NDK_MR *pMr,
  [in]           ULONG AdapterPageCount,
                 const NDK_LOGICAL_ADDRESS *AdapterPageArray,
  [in]           ULONG FBO,
  [in]           SIZE_T Length,
  [in]           PVOID BaseVirtualAddress,
  [in]           ULONG Flags
)
{...}