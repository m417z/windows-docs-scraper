NDK_FN_RECEIVE NdkFnReceive;

NTSTATUS NdkFnReceive(
  [in]           NDK_QP *pNdkQp,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge
)
{...}