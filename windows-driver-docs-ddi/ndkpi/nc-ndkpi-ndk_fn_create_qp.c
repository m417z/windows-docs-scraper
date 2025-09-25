NDK_FN_CREATE_QP NdkFnCreateQp;

NTSTATUS NdkFnCreateQp(
  [in]           NDK_PD *pNdkPd,
  [in]           NDK_CQ *pReceiveCq,
  [in]           NDK_CQ *pInitiatorCq,
  [in, optional] PVOID QPContext,
  [in]           ULONG ReceiveQueueDepth,
  [in]           ULONG InitiatorQueueDepth,
  [in]           ULONG MaxReceiveRequestSge,
  [in]           ULONG MaxInitiatorRequestSge,
  [in]           ULONG InlineDataSize,
  [in]           NDK_FN_CREATE_COMPLETION CreateCompletion,
  [in, optional] PVOID RequestContext,
                 NDK_QP **ppNdkQp
)
{...}