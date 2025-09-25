NDK_FN_BUILD_LAM NdkFnBuildLam;

NTSTATUS NdkFnBuildLam(
  [in]           NDK_ADAPTER *pNdkAdapter,
  [in]           MDL *Mdl,
  [in]           SIZE_T Length,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_LOGICAL_ADDRESS_MAPPING *pNdkLAM,
                 ULONG *pLAMSize,
  [out]          ULONG *pFBO
)
{...}