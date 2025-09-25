NDK_FN_CREATE_QP_WITH_SRQ NdkFnCreateQpWithSrq;

NTSTATUS NdkFnCreateQpWithSrq(
  [in]           NDK_PD *pNdkPd,
  [in]           NDK_CQ *pReceiveCq,
  [in]           NDK_CQ *pInitiatorCq,
  [in]           NDK_SRQ *pSrq,
  [in, optional] PVOID QPContext,
  [in]           ULONG InitiatorQueueDepth,
  [in]           ULONG MaxInitiatorRequestSge,
  [in]           ULONG InlineDataSize,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_QP **ppNdkQp
)
{...}