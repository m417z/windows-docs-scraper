NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION NdkFnControlCqInterruptModeration;

NTSTATUS NdkFnControlCqInterruptModeration(
  [in] NDK_CQ *pNdkCq,
  [in] ULONG ModerationInterval,
  [in] ULONG ModerationCount
)
{...}