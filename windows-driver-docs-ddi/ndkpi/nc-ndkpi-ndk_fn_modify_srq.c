NDK_FN_MODIFY_SRQ NdkFnModifySrq;

NTSTATUS NdkFnModifySrq(
  [in]           NDK_SRQ *pNdkSrq,
  [in]           ULONG SrqDepth,
  [in]           ULONG NotifyThreshold,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}