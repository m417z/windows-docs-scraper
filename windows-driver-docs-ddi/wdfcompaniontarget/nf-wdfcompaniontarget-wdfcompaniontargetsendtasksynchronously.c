NTSTATUS WdfCompanionTargetSendTaskSynchronously(
  [in]           WDFCOMPANIONTARGET     CompanionTarget,
  [in]           USHORT                 TaskQueueIdentifier,
  [in]           ULONG                  TaskOperationCode,
  [in, optional] PWDF_MEMORY_DESCRIPTOR InputBuffer,
  [in, optional] PWDF_MEMORY_DESCRIPTOR OutputBuffer,
  [in, optional] PWDF_TASK_SEND_OPTIONS TaskOptions,
  [out]          PULONG_PTR             BytesReturned
);