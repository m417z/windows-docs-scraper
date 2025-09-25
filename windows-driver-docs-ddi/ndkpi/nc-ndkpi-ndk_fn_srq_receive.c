NDK_FN_SRQ_RECEIVE NdkFnSrqReceive;

NTSTATUS NdkFnSrqReceive(
  [in]           NDK_SRQ *pNdkSrq,
  [in, optional] PVOID RequestContext,
                 const NDK_SGE *pSgl,
  [in]           ULONG nSge
)
{...}