NDK_FN_RESIZE_CQ NdkFnResizeCq;

NTSTATUS NdkFnResizeCq(
  [in]           NDK_CQ *pNdkCq,
  [in]           ULONG CqDepth,
  [in]           NDK_FN_REQUEST_COMPLETION RequestCompletion,
  [in, optional] PVOID RequestContext
)
{...}