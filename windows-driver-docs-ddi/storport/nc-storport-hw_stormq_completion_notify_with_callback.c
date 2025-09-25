HW_STORMQ_COMPLETION_NOTIFY_WITH_CALLBACK HwStormqCompletionNotifyWithCallback;

ULONG HwStormqCompletionNotifyWithCallback(
  PVOID ControllerExtension,
  USHORT CompletionQueueId,
  USHORT SubmissionQueueId,
  USHORT CommandId,
  PHW_STORMQ_COMPLETION_CALLBACK CompletionCallback
)
{...}